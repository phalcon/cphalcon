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
    'file' => '/app/phalcon/Events/EventInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Events',
    'file' => '/app/phalcon/Events/EventInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Events\\EventInterface
 *
 * Interface for Phalcon\\Events\\Event class
 *',
    'file' => '/app/phalcon/Events/EventInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'EventInterface',
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
          'name' => 'getData',
          'docblock' => '**
     * Gets event data
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
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 23,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 23,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Gets event type
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
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 28,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 28,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
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
          'name' => 'isCancelable',
          'docblock' => '**
     * Check whether the event is cancelable
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
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 33,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 33,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
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
          'name' => 'isStopped',
          'docblock' => '**
     * Check whether the event is currently stopped
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
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 38,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 38,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
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
          'name' => 'setData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 43,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/EventInterface.zep',
              'line' => 43,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Sets event data
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/EventInterface.zep',
                  'line' => 43,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 43,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 43,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
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
          'name' => 'setType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Events/EventInterface.zep',
              'line' => 48,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets event type
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/EventInterface.zep',
                  'line' => 48,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 48,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 48,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
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
          'name' => 'stop',
          'docblock' => '**
     * Stops the event preventing propagation
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/EventInterface.zep',
                  'line' => 53,
                  'char' => 47,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/EventInterface.zep',
                'line' => 53,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventInterface.zep',
            'line' => 53,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Events/EventInterface.zep',
          'line' => 53,
          'last-line' => 54,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Events/EventInterface.zep',
      'line' => 54,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Events/EventInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);