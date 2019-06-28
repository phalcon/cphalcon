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
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Adapter',
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Logger\\Formatter\\FormatterInterface',
        'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
        'line' => 13,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\AdapterInterface
 *
 * Interface for Phalcon\\Logger adapters
 *',
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  5 => 
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
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 26,
                'char' => 35,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
              'line' => 26,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Adds a message in the queue
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 26,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'begin',
          'docblock' => '**
     * Starts a transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                  'line' => 31,
                  'char' => 50,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 31,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 31,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'close',
          'docblock' => '**
     * Closes the logger
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
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 36,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 36,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'commit',
          'docblock' => '**
     * Commits the internal transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                  'line' => 41,
                  'char' => 51,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 41,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 41,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'getFormatter',
          'docblock' => '**
     * Returns the internal formatter
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
                  'value' => 'FormatterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                  'line' => 46,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 46,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 46,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'process',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 51,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
              'line' => 51,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Processes the message in the adapter
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 51,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'rollback',
          'docblock' => '**
     * Rollbacks the internal transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                  'line' => 56,
                  'char' => 53,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 56,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 56,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
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
          'name' => 'setFormatter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'formatter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'FormatterInterface',
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 61,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
              'line' => 61,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Sets the message formatter
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                  'line' => 61,
                  'char' => 87,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
                'line' => 61,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
            'line' => 61,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
          'line' => 61,
          'last-line' => 62,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
      'line' => 62,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Logger/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);