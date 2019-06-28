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
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Response',
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
        'name' => 'Phalcon\\Http\\CookieInterface',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 14,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
        'name' => 'Phalcon\\Http\\Response\\CookiesInterface',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 15,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
        'name' => 'Phalcon\\Http\\Cookie\\Exception',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
    'line' => 66,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Response\\Cookies
 *
 * This class is a bag to manage the cookies.
 *
 * A cookies bag is automatically registered as part of the \'response\' service
 * in the DI. By default, cookies are automatically encrypted before being sent
 * to the client and are decrypted when retrieved from the user. To set sign key
 * used to generate a message authentication code use
 * `Phalcon\\Http\\Response\\Cookies::setSignKey()`.
 *
 * ```php
 * use Phalcon\\Di;
 * use Phalcon\\Crypt;
 * use Phalcon\\Http\\Response\\Cookies;
 *
 * $di = new Di();
 *
 * $di->set(
 *     \'crypt\',
 *     function () {
 *         $crypt = new Crypt();
 *
 *         // The `$key\' should have been previously generated in a cryptographically safe way.
 *         $key = "T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3";
 *
 *         $crypt->setKey($key);
 *
 *         return $crypt;
 *     }
 * );
 *
 * $di->set(
 *     \'cookies\',
 *     function () {
 *         $cookies = new Cookies();
 *
 *         // The `$key\' MUST be at least 32 characters long and generated using a
 *         // cryptographically secure pseudo random generator.
 *         $key = "#1dj8$=dp?.ak//j1V$~%*0XaK\\xb1\\x8d\\xa9\\x98\\x054t7w!z%C*F-Jk\\x98\\x05\\\\\\x5c";
 *
 *         $cookies->setSignKey($key);
 *
 *         return $cookies;
 *     }
 * );
 * ```
 *',
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
    'line' => 67,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Cookies',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CookiesInterface',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 67,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Response/Cookies.zep',
        'line' => 68,
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
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 71,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'cookies',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 71,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 73,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'registered',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 73,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 78,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'signKey',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 79,
            'char' => 29,
          ),
          'docblock' => '**
     * The cookie\'s sign key.
     * @var string|null
     *',
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 81,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'useEncryption',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 81,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'useEncryption',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 86,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 86,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'signKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 86,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 86,
              'char' => 81,
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
                  'property' => 'useEncryption',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'useEncryption',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 88,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 88,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 90,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 90,
                  'char' => 14,
                ),
                'name' => 'setSignKey',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'signKey',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 90,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 90,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 90,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 91,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Http\\Response\\Cookies constructor
     *',
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 86,
          'last-line' => 96,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
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
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 97,
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
                  'variable' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 99,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 104,
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
                    'value' => 'cookie',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 104,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 104,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'cookies',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 104,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 104,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 104,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 104,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 104,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 104,
                'char' => 47,
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
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 105,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 106,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 108,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 108,
                  'char' => 16,
                ),
                'name' => 'delete',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 108,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 110,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 110,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Deletes a cookie by its name
     * This method does not removes cookies from the _COOKIE superglobal
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 97,
          'last-line' => 115,
          'char' => 19,
        ),
        2 => 
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
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 116,
              'char' => 37,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 118,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'encryption',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 118,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 118,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 123,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 123,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 123,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookies',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 123,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 123,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 123,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 123,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 123,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cookie',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 124,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 125,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 132,
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
                  'variable' => 'cookie',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CookieInterface',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 132,
                      'char' => 91,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 132,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 132,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 132,
                        'char' => 56,
                      ),
                      'name' => 'get',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'Phalcon\\\\Http\\\\Cookie',
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 132,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 132,
                          'char' => 82,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                  'line' => 132,
                                  'char' => 89,
                                ),
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 132,
                                'char' => 89,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 132,
                            'char' => 90,
                          ),
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 132,
                          'char' => 90,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 132,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 132,
                    'char' => 91,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 132,
                  'char' => 91,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 133,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 133,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 133,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 133,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 135,
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
                    'value' => 'container',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 135,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 135,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 135,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 135,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 139,
                      'char' => 20,
                    ),
                    'name' => 'setDi',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 139,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 139,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 139,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 141,
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
                      'variable' => 'encryption',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 141,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'useEncryption',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 141,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 141,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 141,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 146,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'encryption',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 146,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookie',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 147,
                          'char' => 24,
                        ),
                        'name' => 'useEncryption',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'encryption',
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 147,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 147,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 147,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 148,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookie',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 148,
                          'char' => 24,
                        ),
                        'name' => 'setSignKey',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 148,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'signKey',
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 148,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 148,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 148,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 148,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 149,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 150,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 152,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'cookie',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 152,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets a cookie from the bag
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 117,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 117,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 117,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 116,
          'last-line' => 157,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCookies',
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
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 160,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'cookies',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 160,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 160,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets all cookies from the bag
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 159,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 158,
          'last-line' => 165,
          'char' => 19,
        ),
        4 => 
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
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 168,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 168,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 168,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 169,
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
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 167,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 167,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 167,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 166,
          'last-line' => 174,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 175,
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
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'isset',
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
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 177,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'cookies',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 177,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 177,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 177,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 177,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 177,
                  'char' => 43,
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
                      'value' => '_COOKIE',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 177,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 177,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 177,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 177,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 177,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 178,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a cookie is defined in the bag or exists in the _COOKIE
     * superglobal
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 176,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 176,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 175,
          'last-line' => 182,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingEncryption',
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
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 185,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'useEncryption',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 185,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 185,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns if the bag is automatically encrypting/decrypting cookies
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 183,
          'last-line' => 190,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
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
                  'property' => 'cookies',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 193,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 193,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 195,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 195,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 196,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reset set cookies
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
                  'value' => 'CookiesInterface',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 192,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 192,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 192,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 191,
          'last-line' => 201,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
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
                  'variable' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 204,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 206,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'headers_sent',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 206,
                'char' => 27,
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
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 207,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 210,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 210,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'cookies',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 210,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 210,
                'char' => 37,
              ),
              'value' => 'cookie',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 211,
                      'char' => 20,
                    ),
                    'name' => 'send',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 211,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 212,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 214,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 214,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 215,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sends the cookies to the client
     * Cookies aren\'t sent if headers are sent in the current request
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 203,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 203,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 202,
          'last-line' => 235,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
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
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 237,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 238,
                'char' => 21,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 238,
              'char' => 21,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expire',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 239,
                'char' => 23,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 239,
              'char' => 23,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '/',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 240,
                'char' => 24,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 240,
              'char' => 24,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'secure',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 241,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 241,
              'char' => 27,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 242,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 242,
              'char' => 30,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'httpOnly',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 244,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 244,
              'char' => 5,
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
                  'variable' => 'cookie',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 245,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'encryption',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 245,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 245,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'response',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 245,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 247,
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
                  'variable' => 'encryption',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 247,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'useEncryption',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 247,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 247,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 247,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 252,
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
                    'value' => 'cookie',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 252,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 252,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'cookies',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 252,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 252,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 252,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 252,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 252,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 252,
                'char' => 47,
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
                      'variable' => 'cookie',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'CookieInterface',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 257,
                          'char' => 18,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 254,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 254,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 254,
                            'char' => 51,
                          ),
                          'name' => 'get',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Http\\\\Cookie',
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 255,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 255,
                              'char' => 42,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'array',
                                'left' => 
                                array (
                                  0 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 33,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 33,
                                  ),
                                  2 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'expire',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 41,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 41,
                                  ),
                                  3 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'path',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 47,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 47,
                                  ),
                                  4 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'secure',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 55,
                                  ),
                                  5 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'domain',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 63,
                                  ),
                                  6 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'httpOnly',
                                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                      'line' => 256,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 256,
                                    'char' => 73,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 257,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 257,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 257,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 257,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 257,
                      'char' => 18,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 262,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 262,
                      'char' => 20,
                    ),
                    'name' => 'setDi',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 262,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 262,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 262,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 262,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 262,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 267,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'encryption',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 267,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookie',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 268,
                          'char' => 24,
                        ),
                        'name' => 'useEncryption',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'encryption',
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 268,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 268,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 268,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 270,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookie',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 270,
                          'char' => 24,
                        ),
                        'name' => 'setSignKey',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 270,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'signKey',
                                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                'line' => 270,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 270,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 270,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 270,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 271,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 273,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'cookies',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 273,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'cookie',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 273,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 273,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 274,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 278,
                      'char' => 20,
                    ),
                    'name' => 'setValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 278,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 278,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 278,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 279,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 279,
                      'char' => 20,
                    ),
                    'name' => 'setExpiration',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'expire',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 279,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 279,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 279,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 280,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 280,
                      'char' => 20,
                    ),
                    'name' => 'setPath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 280,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 280,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 280,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 281,
                  'char' => 18,
                ),
                3 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 281,
                      'char' => 20,
                    ),
                    'name' => 'setSecure',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'secure',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 281,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 281,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 281,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 282,
                  'char' => 18,
                ),
                4 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 282,
                      'char' => 20,
                    ),
                    'name' => 'setDomain',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'domain',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 282,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 282,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 282,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 283,
                  'char' => 18,
                ),
                5 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 283,
                      'char' => 20,
                    ),
                    'name' => 'setHttpOnly',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'httpOnly',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 283,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 283,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 283,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 284,
                  'char' => 18,
                ),
                6 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookie',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 284,
                      'char' => 20,
                    ),
                    'name' => 'setSignKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 284,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'signKey',
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 284,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 284,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 284,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 284,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 285,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 290,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 290,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'registered',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 290,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 290,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 290,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 290,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 291,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 291,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 291,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 291,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 293,
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
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 293,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 293,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 293,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 293,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 293,
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
                                    'value' => 'the \'response\' service',
                                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                    'line' => 297,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                                  'line' => 297,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 298,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 298,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 298,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 299,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 301,
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
                      'variable' => 'response',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 301,
                          'char' => 38,
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
                              'value' => 'response',
                              'file' => '/app/phalcon/Http/Response/Cookies.zep',
                              'line' => 301,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Response/Cookies.zep',
                            'line' => 301,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 301,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 301,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 307,
                  'char' => 20,
                ),
                3 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'response',
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 307,
                      'char' => 22,
                    ),
                    'name' => 'setCookies',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Response/Cookies.zep',
                          'line' => 307,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 307,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 307,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 309,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'registered',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Response/Cookies.zep',
                        'line' => 309,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Response/Cookies.zep',
                      'line' => 309,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 310,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 312,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 312,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 313,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a cookie to be sent at the end of the request.
     *
     * This method overrides any cookie set before with the same name.
     *
     * ```php
     * use Phalcon\\Http\\Response\\Cookies;
     *
     * $now = new DateTimeImmutable();
     * $tomorrow = $now->modify(\'tomorrow\');
     *
     * $cookies = new Cookies();
     * $cookies->set(
     *     \'remember-me\',
     *     json_encode([\'user_id\' => 1]),
     *     (int) $tomorrow->format(\'U\'),
     * );
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'CookiesInterface',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 244,
                  'char' => 29,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 244,
                'char' => 29,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 244,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 236,
          'last-line' => 317,
          'char' => 19,
        ),
        10 => 
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
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 318,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 318,
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
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 320,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 320,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 321,
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
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 319,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 318,
          'last-line' => 332,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'signKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 333,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 333,
              'char' => 53,
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
                  'property' => 'signKey',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'signKey',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 335,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 335,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 337,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 337,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 338,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s sign key.
     *
     * The `$signKey\' MUST be at least 32 characters long
     * and generated using a cryptographically secure pseudo random generator.
     *
     * Use NULL to disable cookie signing.
     *
     * @see \\Phalcon\\Security\\Random
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 334,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 334,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 334,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 333,
          'last-line' => 342,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useEncryption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'useEncryption',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 343,
              'char' => 53,
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
                  'property' => 'useEncryption',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'useEncryption',
                    'file' => '/app/phalcon/Http/Response/Cookies.zep',
                    'line' => 345,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 345,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 347,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 347,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Cookies.zep',
              'line' => 348,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set if cookies in the bag must be automatically encrypted/decrypted
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
                  'value' => 'CookiesInterface',
                  'file' => '/app/phalcon/Http/Response/Cookies.zep',
                  'line' => 344,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Cookies.zep',
                'line' => 344,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Cookies.zep',
            'line' => 344,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Cookies.zep',
          'line' => 343,
          'last-line' => 349,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Response/Cookies.zep',
      'line' => 67,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Response/Cookies.zep',
    'line' => 67,
    'char' => 5,
  ),
);