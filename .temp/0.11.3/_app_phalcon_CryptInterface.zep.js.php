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
    'file' => '/app/phalcon/CryptInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/CryptInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Crypt
 *',
    'file' => '/app/phalcon/CryptInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'CryptInterface',
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
          'name' => 'decrypt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 21,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 21,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 21,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Decrypts a text
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 21,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 21,
            'char' => 72,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
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
          'name' => 'decryptBase64',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 26,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 26,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 26,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Decrypt a text that is coded as a base64 string
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 26,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 26,
            'char' => 70,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
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
          'name' => 'encrypt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 31,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 31,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 31,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Encrypts a text
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 31,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 31,
            'char' => 72,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
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
          'name' => 'encryptBase64',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 36,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 36,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 36,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Encrypts a text returning the result as a base64 string
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 36,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 36,
            'char' => 70,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
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
          'name' => 'getAvailableCiphers',
          'docblock' => '**
     * Returns a list of available cyphers
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 41,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 41,
            'char' => 51,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
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
          'name' => 'getAuthTag',
          'docblock' => '**
     * Returns the authentication tag
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 46,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 46,
            'char' => 43,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAuthData',
          'docblock' => '**
     * Returns authentication data
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 51,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 51,
            'char' => 44,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAuthTagLength',
          'docblock' => '**
     * Returns the authentication tag length
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 56,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 56,
            'char' => 46,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCipher',
          'docblock' => '**
     * Returns the current cipher
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 61,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 61,
            'char' => 42,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 61,
          'last-line' => 65,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getKey',
          'docblock' => '**
     * Returns the encryption key
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
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 66,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 66,
            'char' => 39,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthTag',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 71,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Sets the authentication tag
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 71,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 71,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 71,
            'char' => 64,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 76,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets authentication data
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 76,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 76,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 76,
            'char' => 66,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthTagLength',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 81,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets the authentication tag length
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 81,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 81,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 81,
            'char' => 70,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 81,
          'last-line' => 85,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCipher',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cipher',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 86,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the cipher algorithm
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 86,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 86,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 86,
            'char' => 66,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 91,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Sets the encryption key
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 91,
                  'char' => 60,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 91,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 91,
            'char' => 60,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPadding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'scheme',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/CryptInterface.zep',
              'line' => 96,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Changes the padding scheme used.
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/CryptInterface.zep',
                  'line' => 96,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/CryptInterface.zep',
                'line' => 96,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/CryptInterface.zep',
            'line' => 96,
            'char' => 64,
          ),
          'file' => '/app/phalcon/CryptInterface.zep',
          'line' => 96,
          'last-line' => 97,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/CryptInterface.zep',
      'line' => 97,
      'char' => 1,
    ),
    'file' => '/app/phalcon/CryptInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);