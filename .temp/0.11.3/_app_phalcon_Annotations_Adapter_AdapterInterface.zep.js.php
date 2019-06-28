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
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations\\Adapter',
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Annotations\\Reflection',
        'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Annotations\\Collection',
        'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
        'line' => 14,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Annotations\\ReaderInterface',
        'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
        'line' => 15,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This interface must be implemented by adapters in Phalcon\\Annotations
 *',
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  6 => 
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
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 25,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Parses or retrieves all the annotations found in a class
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
                  'value' => 'Reflection',
                  'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                  'line' => 25,
                  'char' => 58,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 25,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 25,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
          'name' => 'getMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'methodName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in a specific method
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                  'line' => 30,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 30,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
          'name' => 'getMethods',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 35,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in all the class\' methods
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
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 35,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 35,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
          'name' => 'getProperty',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 40,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'propertyName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 40,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in a specific property
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                  'line' => 40,
                  'char' => 87,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 40,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 40,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
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
          'name' => 'getProperties',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 45,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in all the class\' methods
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
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 45,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 45,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReader',
          'docblock' => '**
     * Returns the annotation reader
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
                  'value' => 'ReaderInterface',
                  'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                  'line' => 50,
                  'char' => 53,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 50,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
            'line' => 50,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setReader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'reader',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ReaderInterface',
                'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
                'line' => 55,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
              'line' => 55,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Sets the annotations parser
     *',
          'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
          'line' => 55,
          'last-line' => 56,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
      'line' => 56,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);