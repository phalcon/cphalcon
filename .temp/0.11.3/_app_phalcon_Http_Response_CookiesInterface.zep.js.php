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
    'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Response',
    'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
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
        'name' => 'Phalcon\\Http\\CookieInterface',
        'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
        'line' => 13,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Response\\CookiesInterface
 *
 * Interface for Phalcon\\Http\\Response\\Cookies
 *',
    'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'CookiesInterface',
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
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 26,
              'char' => 40,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 26,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 26,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 31,
              'char' => 37,
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
                  'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                  'line' => 31,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 31,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 31,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 36,
              'char' => 37,
            ),
          ),
          'docblock' => '**
     * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 36,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 36,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingEncryption',
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 41,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 41,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
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
                  'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                  'line' => 46,
                  'char' => 50,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 46,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 46,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
          'docblock' => '**
     * Sends the cookies to the client
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 51,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 51,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 37,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 51,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 67,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 84,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 104,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 104,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 127,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 127,
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
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 149,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 56,
              'char' => 149,
            ),
          ),
          'docblock' => '**
     * Sets a cookie to be sent at the end of the request
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
                  'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                  'line' => 56,
                  'char' => 172,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 56,
                'char' => 172,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 56,
            'char' => 172,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        7 => 
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
              'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
              'line' => 61,
              'char' => 53,
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
                  'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                  'line' => 61,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
                'line' => 61,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
            'line' => 61,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
          'line' => 61,
          'last-line' => 62,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
      'line' => 62,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Http/Response/CookiesInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);