<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Db/ColumnInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/ColumnInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Db\\Column
 *',
    'file' => '/app/phalcon/Db/ColumnInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ColumnInterface',
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
              'file' => '/app/phalcon/Db/ColumnInterface.zep',
              'line' => 21,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Restores the internal state of a Phalcon\\Db\\Column object
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
                  'value' => 'ColumnInterface',
                  'file' => '/app/phalcon/Db/ColumnInterface.zep',
                  'line' => 21,
                  'char' => 73,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 21,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 21,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 21,
          'last-line' => 25,
          'char' => 26,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAfterPosition',
          'docblock' => '**
     * Check whether field absolute to position in table
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 26,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 26,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getBindType',
          'docblock' => '**
     * Returns the type of bind handling
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 31,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 31,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getDefault',
          'docblock' => '**
     * Returns default value of column
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 36,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 36,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
     * Returns column name
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 41,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 41,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getScale',
          'docblock' => '**
     * Returns column scale
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 46,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 46,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getSize',
          'docblock' => '**
     * Returns column size
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 51,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 51,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getType',
          'docblock' => '**
     * Returns column type
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 56,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 56,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getTypeReference',
          'docblock' => '**
     * Returns column type reference
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 61,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 61,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'getTypeValues',
          'docblock' => '**
     * Returns column type values
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 66,
                'char' => 46,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 66,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 66,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 66,
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
          'name' => 'hasDefault',
          'docblock' => '**
     * Check whether column has default value
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 72,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 72,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'isAutoIncrement',
          'docblock' => '**
     * Auto-Increment
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 77,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 77,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'isFirst',
          'docblock' => '**
     * Check whether column have first position in table
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 82,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 82,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
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
          'name' => 'isNotNull',
          'docblock' => '**
     * Not null
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 87,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 87,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 87,
          'last-line' => 91,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isNumeric',
          'docblock' => '**
     * Check whether column have an numeric type
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 92,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 92,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 92,
          'last-line' => 96,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPrimary',
          'docblock' => '**
     * Column is part of the primary key?
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 97,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 97,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 97,
          'last-line' => 101,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUnsigned',
          'docblock' => '**
     * Returns true if number column is unsigned
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
                'file' => '/app/phalcon/Db/ColumnInterface.zep',
                'line' => 102,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ColumnInterface.zep',
            'line' => 102,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Db/ColumnInterface.zep',
          'line' => 102,
          'last-line' => 103,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/ColumnInterface.zep',
      'line' => 103,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Db/ColumnInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);