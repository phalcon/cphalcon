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
    'file' => '/app/phalcon/Assets/AssetInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/AssetInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for custom Phalcon\\Assets reources
 *',
    'file' => '/app/phalcon/Assets/AssetInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'AssetInterface',
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
          'name' => 'getAssetKey',
          'docblock' => '**
     * Gets the asset\'s key.
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
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 21,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 21,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'getAttributes',
          'docblock' => '**
     * Gets extra HTML attributes.
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
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 26,
                'char' => 46,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 26,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 26,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'getFilter',
          'docblock' => '**
     * Gets if the asset must be filtered or not.
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
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 31,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 31,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'getType',
          'docblock' => '**
     * Gets the asset\'s type.
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
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 36,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 36,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'setAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/AssetInterface.zep',
              'line' => 41,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets extra HTML attributes.
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/AssetInterface.zep',
                  'line' => 41,
                  'char' => 72,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 41,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 41,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'setFilter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/AssetInterface.zep',
              'line' => 46,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Sets if the asset must be filtered or not.
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/AssetInterface.zep',
                  'line' => 46,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 46,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 46,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
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
          'name' => 'setType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/AssetInterface.zep',
              'line' => 51,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Sets the asset\'s type.
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/AssetInterface.zep',
                  'line' => 51,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/AssetInterface.zep',
                'line' => 51,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/AssetInterface.zep',
            'line' => 51,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Assets/AssetInterface.zep',
          'line' => 51,
          'last-line' => 52,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/AssetInterface.zep',
      'line' => 52,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Assets/AssetInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);