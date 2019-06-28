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
    'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
        'line' => 13,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\AdapterInterface
 *
 * Interface for Phalcon\\Logger adapters
 *',
    'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'clear',
          'docblock' => '**
     * Flushes/clears the cache
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 25,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 25,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'decrement',
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
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Decrements a stored number
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 30,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 30,
          'last-line' => 34,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 35,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Deletes data from the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 35,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 35,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 35,
          'last-line' => 39,
          'char' => 19,
        ),
        3 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 40,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 40,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 40,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 40,
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
          'name' => 'getAdapter',
          'docblock' => '**
     * Returns the already connected adapter or connects to the backend
     * server(s)
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 46,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 46,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
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
          'name' => 'getKeys',
          'docblock' => '**
     * Returns all the keys stored
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 51,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 51,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
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
          'name' => 'getPrefix',
          'docblock' => '**
     * Returns the prefix for the keys
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 56,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 56,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
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
          'name' => 'has',
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
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 61,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Checks if an element exists in the cache
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 61,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 61,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 61,
          'last-line' => 65,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'increment',
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
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 66,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 66,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 66,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Increments a stored number
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 66,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 66,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 66,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 66,
          'last-line' => 70,
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 71,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 71,
              'char' => 47,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 71,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
              'line' => 71,
              'char' => 63,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
                'line' => 71,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
            'line' => 71,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
          'line' => 71,
          'last-line' => 72,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
      'line' => 72,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Storage/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);