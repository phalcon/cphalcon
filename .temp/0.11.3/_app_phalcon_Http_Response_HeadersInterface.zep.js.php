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
    'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Response',
    'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Response\\HeadersInterface
 *
 * Interface for Phalcon\\Http\\Response\\Headers compatible bags
 *',
    'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'HeadersInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '__set_state',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 23,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Restore a \\Phalcon\\Http\\Response\\Headers object
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
                  'value' => 'HeadersInterface',
                  'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                  'line' => 23,
                  'char' => 74,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                'line' => 23,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
            'line' => 23,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 26,
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 28,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Gets a header value from the internal bag
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
                'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                'line' => 28,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                'line' => 28,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
            'line' => 28,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 28,
          'last-line' => 32,
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 33,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Returns true if the header is set, false otherwise
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
                'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                'line' => 33,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
            'line' => 33,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
          'docblock' => '**
     * Reset set headers
     *',
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
          'docblock' => '**
     * Sends the headers to the client
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
                'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
                'line' => 43,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
            'line' => 43,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        5 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 48,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 48,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Sets a header to be sent at the end of the request
     *',
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'header',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
              'line' => 53,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets a raw header to be sent at the end of the request
     *',
          'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
          'line' => 53,
          'last-line' => 54,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
      'line' => 54,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Http/Response/HeadersInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);