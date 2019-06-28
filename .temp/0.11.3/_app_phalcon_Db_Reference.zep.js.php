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
    'file' => '/app/phalcon/Db/Reference.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/Reference.zep',
    'line' => 33,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Allows to define reference constraints on tables
 *
 *```php
 * $reference = new \\Phalcon\\Db\\Reference(
 *     "field_fk",
 *     [
 *         "referencedSchema"  => "invoicing",
 *         "referencedTable"   => "products",
 *         "columns"           => [
 *             "producttype",
 *             "product_code",
 *         ],
 *         "referencedColumns" => [
 *             "type",
 *             "code",
 *         ],
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Db/Reference.zep',
    'line' => 34,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Reference',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ReferenceInterface',
        'file' => '/app/phalcon/Db/Reference.zep',
        'line' => 35,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'columns',
          'docblock' => '**
     * Local reference columns
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 41,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 47,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'docblock' => '**
     * Constraint name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 48,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 54,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'referencedColumns',
          'docblock' => '**
     * Referenced Columns
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 55,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 61,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'referencedSchema',
          'docblock' => '**
     * Referenced Schema
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 62,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 68,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'referencedTable',
          'docblock' => '**
     * Referenced Table
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 69,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 75,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'schemaName',
          'docblock' => '**
     * Schema name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 76,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 82,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'onDelete',
          'docblock' => '**
     * ON DELETE
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 83,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 89,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'onUpdate',
          'docblock' => '**
     * ON UPDATE
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 90,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 94,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 95,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 95,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 97,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'schema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 97,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 97,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 97,
                  'char' => 63,
                ),
                4 => 
                array (
                  'variable' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 98,
                  'char' => 30,
                ),
                5 => 
                array (
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 98,
                  'char' => 40,
                ),
                6 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 98,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 100,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 100,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 100,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 102,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'referencedTable',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 102,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 102,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'referencedTable',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 102,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 102,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 102,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 102,
                  'char' => 73,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 102,
                'char' => 73,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Referenced table is required',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 103,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 103,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 103,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 104,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 106,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'referencedTable',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referencedTable',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 106,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 106,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 108,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 108,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 108,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 108,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 108,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 108,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 108,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 108,
                'char' => 57,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Foreign key columns are required',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 109,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 109,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 109,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 110,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 112,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 112,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 112,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 114,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'referencedColumns',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 114,
                      'char' => 77,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 114,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'referencedColumns',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 114,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 114,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 114,
                    'char' => 77,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 114,
                  'char' => 77,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 114,
                'char' => 77,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Referenced columns of the foreign key are required',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 117,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 117,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 117,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 120,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'referencedColumns',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referencedColumns',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 120,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 120,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 122,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 122,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 122,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'schema',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 122,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 122,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 122,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'schemaName',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 123,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 123,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 124,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 126,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 126,
                  'char' => 65,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 126,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'referencedSchema',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 126,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 126,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 126,
                'char' => 65,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'referencedSchema',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'referencedSchema',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 127,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 127,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 128,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 130,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'onDelete',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 130,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 130,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'onDelete',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 130,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 130,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 130,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'onDelete',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'onDelete',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 131,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 131,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 132,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 134,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 134,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 134,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'onUpdate',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 134,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 134,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 134,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'onUpdate',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'onUpdate',
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 135,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 135,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 136,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 138,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 138,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 138,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 138,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'referencedColumns',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 138,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 138,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 138,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 138,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 138,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Number of columns is not equals than the number of columns referenced',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 141,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 141,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 141,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Db\\Reference constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Reference.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 95,
          'last-line' => 147,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 148,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 150,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 150,
                  'char' => 46,
                ),
                2 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 150,
                  'char' => 55,
                ),
                3 => 
                array (
                  'variable' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 150,
                  'char' => 74,
                ),
                4 => 
                array (
                  'variable' => 'constraintName',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 151,
                  'char' => 27,
                ),
                5 => 
                array (
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 151,
                  'char' => 37,
                ),
                6 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 151,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 153,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'constraintName',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 153,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 153,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'referenceName',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 153,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 153,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 153,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 153,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'constraintName',
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 154,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 154,
                            'char' => 52,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'name',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 154,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 154,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 154,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 154,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 154,
                    'char' => 59,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Exception',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'name parameter is required',
                              'file' => '/app/phalcon/Db/Reference.zep',
                              'line' => 155,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 155,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Reference.zep',
                        'line' => 155,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 156,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 157,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 159,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 159,
                  'char' => 55,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 159,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'referencedSchema',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 159,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 159,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 159,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 160,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 160,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 160,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'referencedTable',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 160,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 160,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 160,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 161,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 161,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 161,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 161,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 161,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 161,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 162,
              'char' => 13,
            ),
            5 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 162,
                  'char' => 57,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 162,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'referencedColumns',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 162,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 162,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 162,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 163,
              'char' => 13,
            ),
            6 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'onDelete',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 163,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 163,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'onDelete',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 163,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 163,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 163,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 164,
              'char' => 13,
            ),
            7 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 164,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 164,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'onUpdate',
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 164,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 164,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 164,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 166,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Reference',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'constraintName',
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 167,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 167,
                    'char' => 27,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array',
                      'left' => 
                      array (
                        0 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'referencedSchema',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 169,
                            'char' => 33,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'referencedSchema',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 169,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 169,
                          'char' => 52,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'referencedTable',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 170,
                            'char' => 32,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'referencedTable',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 170,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 170,
                          'char' => 51,
                        ),
                        2 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'columns',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 171,
                            'char' => 24,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columns',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 171,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 171,
                          'char' => 43,
                        ),
                        3 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'referencedColumns',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 172,
                            'char' => 34,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'referencedColumns',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 172,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 172,
                          'char' => 53,
                        ),
                        4 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'onDelete',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 173,
                            'char' => 25,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'onDelete',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 173,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 173,
                          'char' => 44,
                        ),
                        5 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => 'onUpdate',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 174,
                            'char' => 25,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'onUpdate',
                            'file' => '/app/phalcon/Db/Reference.zep',
                            'line' => 175,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Db/Reference.zep',
                          'line' => 175,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Reference.zep',
                      'line' => 176,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Reference.zep',
                    'line' => 176,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 176,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Reference.zep',
              'line' => 177,
              'char' => 5,
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
                  'file' => '/app/phalcon/Db/Reference.zep',
                  'line' => 149,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Reference.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Reference.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Reference.zep',
          'line' => 148,
          'last-line' => 178,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Db/Reference.zep',
      'line' => 34,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Reference.zep',
    'line' => 34,
    'char' => 5,
  ),
);