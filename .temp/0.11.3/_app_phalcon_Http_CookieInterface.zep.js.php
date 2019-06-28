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
    'file' => '/app/phalcon/Http/CookieInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http',
    'file' => '/app/phalcon/Http/CookieInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Http\\Cookie
 *',
    'file' => '/app/phalcon/Http/CookieInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'CookieInterface',
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
          'docblock' => '**
     * Deletes the cookie
     *',
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 21,
          'last-line' => 25,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDomain',
          'docblock' => '**
     * Returns the domain that the cookie is available to
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 26,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 26,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExpiration',
          'docblock' => '**
     * Returns the current expiration time
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 31,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 31,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpOnly',
          'docblock' => '**
     * Returns if the cookie is accessible only through the HTTP protocol
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 36,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 36,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
          'docblock' => '**
     * Returns the current cookie\'s name
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 41,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 41,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPath',
          'docblock' => '**
     * Returns the current cookie\'s path
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 46,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 46,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 46,
          'last-line' => 51,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSecure',
          'docblock' => '**
     * Returns whether the cookie must only be sent when the connection is
     * secure (HTTPS)
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 52,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 52,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 52,
          'last-line' => 56,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 57,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 57,
              'char' => 48,
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 57,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 57,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Returns the cookie\'s value.
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 57,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 57,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 57,
          'last-line' => 61,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingEncryption',
          'docblock' => '**
     * Check if the cookie is using implicit encryption
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
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 62,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 62,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 62,
          'last-line' => 66,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
          'docblock' => '**
     * Sends the cookie to the HTTP client
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 67,
                  'char' => 48,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 67,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 67,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 67,
          'last-line' => 71,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDomain',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 72,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the domain that the cookie is available to
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 72,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 72,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 72,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 72,
          'last-line' => 76,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setExpiration',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expire',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 77,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s expiration time
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 77,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 77,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 77,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 77,
          'last-line' => 81,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHttpOnly',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'httpOnly',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 82,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie is accessible only through the HTTP protocol
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 82,
                  'char' => 68,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 82,
                'char' => 68,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 82,
            'char' => 68,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 82,
          'last-line' => 86,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 87,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s expiration time
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 87,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 87,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 87,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 87,
          'last-line' => 92,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSecure',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'secure',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 93,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie must only be sent when the connection is secure
     * (HTTPS)
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 93,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 93,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 93,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 93,
          'last-line' => 99,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 100,
              'char' => 35,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s value
     *
     * @param string value
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 100,
                  'char' => 57,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 100,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 100,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 100,
          'last-line' => 104,
          'char' => 19,
        ),
        16 => 
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
              'file' => '/app/phalcon/Http/CookieInterface.zep',
              'line' => 105,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie must be encrypted/decrypted automatically
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
                  'file' => '/app/phalcon/Http/CookieInterface.zep',
                  'line' => 105,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/CookieInterface.zep',
                'line' => 105,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/CookieInterface.zep',
            'line' => 105,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Http/CookieInterface.zep',
          'line' => 105,
          'last-line' => 106,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/CookieInterface.zep',
      'line' => 106,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Http/CookieInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);