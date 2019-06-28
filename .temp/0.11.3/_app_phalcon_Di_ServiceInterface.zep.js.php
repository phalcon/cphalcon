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
    'file' => '/app/phalcon/Di/ServiceInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/ServiceInterface.zep',
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
        'file' => '/app/phalcon/Di/ServiceInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/ServiceInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents a service in the services container
 *',
    'file' => '/app/phalcon/Di/ServiceInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ServiceInterface',
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
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 23,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Restore the internal state of a service
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di/ServiceInterface.zep',
                  'line' => 23,
                  'char' => 80,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 23,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 23,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
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
          'name' => 'getDefinition',
          'docblock' => '**
     * Returns the service definition
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
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 28,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 28,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 28,
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
          'name' => 'getParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 35,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Returns a parameter in a specific position
     *
     * @return array
     *',
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
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
          'name' => 'isResolved',
          'docblock' => '**
     * Returns true if the service was resolved
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
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 40,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 40,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 40,
          'last-line' => 44,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isShared',
          'docblock' => '**
     * Check whether the service is shared or not
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
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 45,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 45,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 45,
          'last-line' => 51,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'resolve',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 52,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 52,
              'char' => 46,
            ),
            1 => 
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
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 52,
                'char' => 70,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 52,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 52,
              'char' => 78,
            ),
          ),
          'docblock' => '**
     * Resolves the service
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 52,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 52,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 52,
          'last-line' => 56,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefinition',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 57,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Set the service definition
     *',
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 57,
          'last-line' => 61,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 62,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameter',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 62,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Changes a parameter in the definition without resolve the service
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di/ServiceInterface.zep',
                  'line' => 62,
                  'char' => 87,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/ServiceInterface.zep',
                'line' => 62,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/ServiceInterface.zep',
            'line' => 62,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 62,
          'last-line' => 66,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceInterface.zep',
              'line' => 67,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Sets if the service is shared or not
     *',
          'file' => '/app/phalcon/Di/ServiceInterface.zep',
          'line' => 67,
          'last-line' => 68,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/ServiceInterface.zep',
      'line' => 68,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Di/ServiceInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);