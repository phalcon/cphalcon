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
    'file' => '/app/phalcon/Db/ReferenceInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/ReferenceInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Db\\Reference
 *',
    'file' => '/app/phalcon/Db/ReferenceInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ReferenceInterface',
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
              'file' => '/app/phalcon/Db/ReferenceInterface.zep',
              'line' => 21,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Restore a Phalcon\\Db\\Reference object from export
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
                  'value' => 'ReferenceInterface',
                  'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                  'line' => 21,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 21,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 21,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getColumns',
          'docblock' => '**
     * Gets local columns which reference is based
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 26,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 26,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getName',
          'docblock' => '**
     * Gets the index name
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 31,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 31,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getOnDelete',
          'docblock' => '**
     * Gets the referenced on delete
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 36,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 36,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getOnUpdate',
          'docblock' => '**
     * Gets the referenced on update
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 41,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 41,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getReferencedColumns',
          'docblock' => '**
     * Gets referenced columns
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 46,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 46,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getReferencedSchema',
          'docblock' => '**
     * Gets the schema where referenced table is
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 51,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 51,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getReferencedTable',
          'docblock' => '**
     * Gets the referenced table
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 56,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 56,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
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
          'name' => 'getSchemaName',
          'docblock' => '**
     * Gets the schema where referenced table is
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
                'file' => '/app/phalcon/Db/ReferenceInterface.zep',
                'line' => 61,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ReferenceInterface.zep',
            'line' => 61,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db/ReferenceInterface.zep',
          'line' => 61,
          'last-line' => 62,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/ReferenceInterface.zep',
      'line' => 62,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Db/ReferenceInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);