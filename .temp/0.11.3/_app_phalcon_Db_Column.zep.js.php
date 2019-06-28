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
    'file' => '/app/phalcon/Db/Column.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/Column.zep',
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
        'name' => 'Phalcon\\Db\\Exception',
        'file' => '/app/phalcon/Db/Column.zep',
        'line' => 13,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Column.zep',
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
        'name' => 'Phalcon\\Db\\ColumnInterface',
        'file' => '/app/phalcon/Db/Column.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Column.zep',
    'line' => 38,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Allows to define columns to be used on create or alter table operations
 *
 *```php
 * use Phalcon\\Db\\Column as Column;
 *
 * // Column definition
 * $column = new Column(
 *     "id",
 *     [
 *         "type"          => Column::TYPE_INTEGER,
 *         "size"          => 10,
 *         "unsigned"      => true,
 *         "notNull"       => true,
 *         "autoIncrement" => true,
 *         "first"         => true,
 *     ]
 * );
 *
 * // Add column to existing table
 * $connection->addColumn("robots", null, $column);
 *```
 *',
    'file' => '/app/phalcon/Db/Column.zep',
    'line' => 39,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Column',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ColumnInterface',
        'file' => '/app/phalcon/Db/Column.zep',
        'line' => 40,
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
          'name' => 'after',
          'docblock' => '**
     * Column Position
     *
     * @var string
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 222,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'autoIncrement',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 223,
            'char' => 36,
          ),
          'docblock' => '**
     * Column is autoIncrement?
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 227,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'bindType',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 228,
            'char' => 27,
          ),
          'docblock' => '**
     * Bind Type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 232,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => '_default',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 233,
            'char' => 31,
          ),
          'docblock' => '**
     * Default column value
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 233,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 239,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'first',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 240,
            'char' => 28,
          ),
          'docblock' => '**
     * Position is first
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 244,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'isNumeric',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 245,
            'char' => 32,
          ),
          'docblock' => '**
     * The column have some numeric type?
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 251,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'docblock' => '**
     * Column\'s name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 252,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 258,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'notNull',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 259,
            'char' => 30,
          ),
          'docblock' => '**
     * Column not nullable?
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 263,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'primary',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 264,
            'char' => 30,
          ),
          'docblock' => '**
     * Column is part of the primary key?
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 270,
          'char' => 6,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'scale',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 271,
            'char' => 25,
          ),
          'docblock' => '**
     * Integer column number scale
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 271,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 277,
          'char' => 6,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'size',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 278,
            'char' => 24,
          ),
          'docblock' => '**
     * Integer column size
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 278,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 284,
          'char' => 6,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'docblock' => '**
     * Column data type
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 285,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 291,
          'char' => 6,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'typeReference',
          'default' => 
          array (
            'type' => 'int',
            'value' => '-1',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 292,
            'char' => 34,
          ),
          'docblock' => '**
     * Column data type reference
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 292,
              'char' => 40,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 298,
          'char' => 6,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'typeValues',
          'docblock' => '**
     * Column data type values
     *
     * @var array|string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 299,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 305,
          'char' => 6,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'unsigned',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 306,
            'char' => 31,
          ),
          'docblock' => '**
     * Integer column unsigned?
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 310,
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
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 311,
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
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 311,
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
                  'variable' => 'type',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'notNull',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'primary',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'size',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 41,
                ),
                4 => 
                array (
                  'variable' => 'scale',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 48,
                ),
                5 => 
                array (
                  'variable' => 'dunsigned',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 59,
                ),
                6 => 
                array (
                  'variable' => 'first',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 66,
                ),
                7 => 
                array (
                  'variable' => 'after',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 313,
                  'char' => 73,
                ),
                8 => 
                array (
                  'variable' => 'bindType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 314,
                  'char' => 21,
                ),
                9 => 
                array (
                  'variable' => 'isNumeric',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 314,
                  'char' => 32,
                ),
                10 => 
                array (
                  'variable' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 314,
                  'char' => 47,
                ),
                11 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 314,
                  'char' => 61,
                ),
                12 => 
                array (
                  'variable' => 'typeReference',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 314,
                  'char' => 76,
                ),
                13 => 
                array (
                  'variable' => 'typeValues',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 315,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 317,
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
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 317,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 317,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 322,
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
                      'value' => 'type',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 322,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 322,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'type',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 322,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 322,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 322,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 322,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 322,
                'char' => 51,
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
                          'value' => 'Column type is required',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 323,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 323,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 323,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 324,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 326,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 326,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 326,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 328,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'typeReference',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 328,
                  'char' => 59,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 328,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'typeReference',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 328,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 328,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 328,
                'char' => 59,
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
                      'property' => 'typeReference',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'typeReference',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 329,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 329,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 330,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 332,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'typeValues',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 332,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 332,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'typeValues',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 332,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 332,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 332,
                'char' => 53,
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
                      'property' => 'typeValues',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'typeValues',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 333,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 333,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 334,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 339,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'notNull',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 339,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 339,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'notNull',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 339,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 339,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 339,
                'char' => 47,
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
                      'property' => 'notNull',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'notNull',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 340,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 340,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 341,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 346,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'primary',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 346,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 346,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'primary',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 346,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 346,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 346,
                'char' => 47,
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
                      'property' => 'primary',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'primary',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 347,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 347,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 348,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 350,
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
                  'value' => 'size',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 350,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 350,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'size',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 350,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 350,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 350,
                'char' => 41,
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
                      'property' => 'size',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'size',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 351,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 351,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 352,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 357,
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
                  'value' => 'scale',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 357,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 357,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'scale',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 357,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 357,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 357,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 358,
                    'char' => 25,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 360,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_INTEGER',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 360,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 360,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 361,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 361,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_FLOAT',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 361,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 361,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 362,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 362,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_DECIMAL',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 362,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 362,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 363,
                      'char' => 20,
                    ),
                    3 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 363,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_DOUBLE',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 363,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 363,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 364,
                      'char' => 20,
                    ),
                    4 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 364,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_BIGINTEGER',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 364,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 364,
                        'char' => 43,
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
                              'property' => 'scale',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'scale',
                                'file' => '/app/phalcon/Db/Column.zep',
                                'line' => 365,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 365,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 366,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 368,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 368,
                      'char' => 23,
                    ),
                    5 => 
                    array (
                      'type' => 'default',
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
                                  'value' => 'Column type does not support scale parameter',
                                  'file' => '/app/phalcon/Db/Column.zep',
                                  'line' => 371,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Column.zep',
                                'line' => 371,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 371,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 372,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 372,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 373,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 378,
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
                  'value' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 378,
                  'char' => 52,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 378,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'default',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 378,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 378,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 378,
                'char' => 52,
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
                      'property' => '_default',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultValue',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 379,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 379,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 380,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 385,
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
                  'value' => 'dunsigned',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 385,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 385,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'unsigned',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 385,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 385,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 385,
                'char' => 50,
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
                      'property' => 'unsigned',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dunsigned',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 386,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 386,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 387,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 392,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'isNumeric',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 392,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 392,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'isNumeric',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 392,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 392,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 392,
                'char' => 51,
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
                      'property' => 'isNumeric',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'isNumeric',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 393,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 393,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 394,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 399,
              'char' => 10,
            ),
            13 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 399,
                  'char' => 59,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 399,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'autoIncrement',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 399,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 399,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 399,
                'char' => 59,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'autoIncrement',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 400,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 400,
                    'char' => 31,
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
                          'property' => 'autoIncrement',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 401,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 401,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 402,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'switch',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 403,
                        'char' => 29,
                      ),
                      'clauses' => 
                      array (
                        0 => 
                        array (
                          'type' => 'case',
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'self',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 404,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_BIGINTEGER',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 404,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 404,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 405,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'case',
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'self',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 405,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_INTEGER',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 405,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 405,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 406,
                          'char' => 24,
                        ),
                        2 => 
                        array (
                          'type' => 'case',
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'self',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 406,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_MEDIUMINTEGER',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 406,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 406,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 407,
                          'char' => 24,
                        ),
                        3 => 
                        array (
                          'type' => 'case',
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'self',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 407,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_SMALLINTEGER',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 407,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 407,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 408,
                          'char' => 24,
                        ),
                        4 => 
                        array (
                          'type' => 'case',
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'self',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 408,
                              'char' => 48,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_TINYINTEGER',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 408,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 408,
                            'char' => 48,
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
                                  'property' => 'autoIncrement',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Db/Column.zep',
                                    'line' => 409,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Db/Column.zep',
                                  'line' => 409,
                                  'char' => 55,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 410,
                              'char' => 29,
                            ),
                            1 => 
                            array (
                              'type' => 'break',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 412,
                              'char' => 27,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 412,
                          'char' => 27,
                        ),
                        5 => 
                        array (
                          'type' => 'default',
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
                                      'value' => 'Column type cannot be auto-increment',
                                      'file' => '/app/phalcon/Db/Column.zep',
                                      'line' => 415,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Db/Column.zep',
                                    'line' => 415,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Column.zep',
                                'line' => 415,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 416,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 416,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 417,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 418,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 423,
              'char' => 10,
            ),
            14 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'first',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 423,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 423,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'first',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 423,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 423,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 423,
                'char' => 43,
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
                      'property' => 'first',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'first',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 424,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 424,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 425,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 430,
              'char' => 10,
            ),
            15 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'after',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 430,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 430,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'after',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 430,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 430,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 430,
                'char' => 43,
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
                      'property' => 'after',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'after',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 431,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 431,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 432,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 437,
              'char' => 10,
            ),
            16 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'bindType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 437,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 437,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'bindType',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 437,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 437,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 437,
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
                      'property' => 'bindType',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindType',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 438,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 438,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 439,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 440,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Db\\Column constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 312,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 311,
          'last-line' => 444,
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
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 445,
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
                  'variable' => 'columnType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'notNull',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'size',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'dunsigned',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'after',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'isNumeric',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 67,
                ),
                6 => 
                array (
                  'variable' => 'first',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 447,
                  'char' => 74,
                ),
                7 => 
                array (
                  'variable' => 'bindType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 21,
                ),
                8 => 
                array (
                  'variable' => 'primary',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 30,
                ),
                9 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 42,
                ),
                10 => 
                array (
                  'variable' => 'scale',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 49,
                ),
                11 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 63,
                ),
                12 => 
                array (
                  'variable' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 448,
                  'char' => 78,
                ),
                13 => 
                array (
                  'variable' => 'columnTypeReference',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 449,
                  'char' => 32,
                ),
                14 => 
                array (
                  'variable' => 'columnTypeValues',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 449,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 450,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 450,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 452,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'columnName',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 452,
                    'char' => 48,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 452,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'columnName',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 452,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 452,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 452,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 452,
                'char' => 48,
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
                          'value' => 'columnName',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 453,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 453,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'name',
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 453,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 453,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 453,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 453,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 453,
                    'char' => 55,
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
                              'value' => 'Column name is required',
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 454,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Db/Column.zep',
                            'line' => 454,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 454,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 455,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 456,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 458,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 458,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 458,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 460,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columnType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 460,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 460,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'type',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 460,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 460,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 460,
                'char' => 42,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 461,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnType',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 461,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 461,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 462,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 464,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columnTypeReference',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 464,
                  'char' => 60,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 464,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'typeReference',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 464,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 464,
                  'char' => 60,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 464,
                'char' => 60,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'typeReference',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 465,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnTypeReference',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 465,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 465,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 466,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'typeReference',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 467,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '-1',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 467,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 467,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 468,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 470,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columnTypeValues',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 470,
                  'char' => 54,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 470,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'typeValues',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 470,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 470,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 470,
                'char' => 54,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'typeValues',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 471,
                          'char' => 38,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnTypeValues',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 471,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 471,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 472,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 474,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'notNull',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 474,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 474,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'notNull',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 474,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 474,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 474,
                'char' => 41,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'notNull',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 475,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'notNull',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 475,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 475,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 476,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 478,
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
                  'value' => 'primary',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 478,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 478,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'primary',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 478,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 478,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 478,
                'char' => 41,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'primary',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 479,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'primary',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 479,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 479,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 480,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 482,
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
                  'value' => 'size',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 482,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 482,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'size',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 482,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 482,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 482,
                'char' => 35,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'size',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 483,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'size',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 483,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 483,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 484,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 486,
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
                  'value' => 'scale',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 486,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 486,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'scale',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 486,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 486,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 486,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 488,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 488,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 488,
                    'char' => 37,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 490,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_INTEGER',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 490,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 490,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 491,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 491,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_FLOAT',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 491,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 491,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 492,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 492,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_DECIMAL',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 492,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 492,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 493,
                      'char' => 20,
                    ),
                    3 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 493,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_DOUBLE',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 493,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 493,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 494,
                      'char' => 20,
                    ),
                    4 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 494,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_BIGINTEGER',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 494,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 494,
                        'char' => 43,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'scale',
                                  'file' => '/app/phalcon/Db/Column.zep',
                                  'line' => 495,
                                  'char' => 41,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'scale',
                                'file' => '/app/phalcon/Db/Column.zep',
                                'line' => 495,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Db/Column.zep',
                              'line' => 495,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 496,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 497,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 497,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 498,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 500,
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
                  'value' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 500,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 500,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'default',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 500,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 500,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 500,
                'char' => 46,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'default',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 501,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultValue',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 501,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 501,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 502,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 504,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'dunsigned',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 504,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 504,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'unsigned',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 504,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 504,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 504,
                'char' => 44,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'unsigned',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 505,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dunsigned',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 505,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 505,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 506,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 508,
              'char' => 10,
            ),
            13 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 508,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 508,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'autoIncrement',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 508,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 508,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 508,
                'char' => 53,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'autoIncrement',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 509,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'autoIncrement',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 509,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 509,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 510,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 512,
              'char' => 10,
            ),
            14 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'isNumeric',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 512,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 512,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'isNumeric',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 512,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 512,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 512,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'isNumeric',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 513,
                          'char' => 37,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'isNumeric',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 513,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 513,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 514,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 516,
              'char' => 10,
            ),
            15 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'first',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 516,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 516,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'first',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 516,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 516,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 516,
                'char' => 37,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'first',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 517,
                          'char' => 33,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'first',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 517,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 517,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 518,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 520,
              'char' => 10,
            ),
            16 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'after',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 520,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 520,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'after',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 520,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 520,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 520,
                'char' => 37,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'after',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 521,
                          'char' => 33,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'after',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 521,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 521,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 522,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 524,
              'char' => 10,
            ),
            17 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'bindType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 524,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 524,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'bindType',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 524,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 524,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 524,
                'char' => 43,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'bindType',
                          'file' => '/app/phalcon/Db/Column.zep',
                          'line' => 525,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindType',
                        'file' => '/app/phalcon/Db/Column.zep',
                        'line' => 525,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 525,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 526,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 528,
              'char' => 14,
            ),
            18 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'self',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnName',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 528,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 528,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Db/Column.zep',
                      'line' => 528,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 528,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 528,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 529,
              'char' => 5,
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
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 446,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 446,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 446,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 445,
          'last-line' => 533,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAfterPosition',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 536,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'after',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 536,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 536,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 537,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 535,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 535,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 534,
          'last-line' => 541,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindType',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 544,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'bindType',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 544,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 544,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 545,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 543,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 543,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 542,
          'last-line' => 549,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasDefault',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 552,
                  'char' => 17,
                ),
                'name' => 'isAutoIncrement',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 552,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 553,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 554,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 556,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 556,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_default',
                    'file' => '/app/phalcon/Db/Column.zep',
                    'line' => 556,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 556,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 556,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 556,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 557,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 551,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 551,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 550,
          'last-line' => 561,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAutoIncrement',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 564,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 564,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 564,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 565,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 563,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 563,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 562,
          'last-line' => 569,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isFirst',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 572,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'first',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 572,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 572,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 573,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 571,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 571,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 570,
          'last-line' => 577,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isNotNull',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 580,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'notNull',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 580,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 580,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 581,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 579,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 579,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 578,
          'last-line' => 585,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isNumeric',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 588,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'isNumeric',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 588,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 588,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 589,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 587,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 587,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 586,
          'last-line' => 593,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPrimary',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 596,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'primary',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 596,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 596,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 597,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 595,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 595,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 594,
          'last-line' => 601,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUnsigned',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 604,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'unsigned',
                  'file' => '/app/phalcon/Db/Column.zep',
                  'line' => 604,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 604,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Db/Column.zep',
              'line' => 605,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Column.zep',
                'line' => 603,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 603,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 602,
          'last-line' => 606,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_BLOB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 44,
            'char' => 30,
          ),
          'docblock' => '**
     * Bind Type Blob
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 48,
          'char' => 6,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_BOOL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 49,
            'char' => 30,
          ),
          'docblock' => '**
     * Bind Type Bool
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 53,
          'char' => 6,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_DECIMAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '32',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 54,
            'char' => 34,
          ),
          'docblock' => '**
     * Bind Type Decimal
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 58,
          'char' => 6,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_INT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 59,
            'char' => 29,
          ),
          'docblock' => '**
     * Bind Type Integer
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 63,
          'char' => 6,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_NULL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 64,
            'char' => 30,
          ),
          'docblock' => '**
     * Bind Type Null
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 68,
          'char' => 6,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'BIND_PARAM_STR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 69,
            'char' => 29,
          ),
          'docblock' => '**
     * Bind Type String
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 73,
          'char' => 6,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'BIND_SKIP',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1024',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 74,
            'char' => 27,
          ),
          'docblock' => '**
     * Skip binding by type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 78,
          'char' => 6,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_BIGINTEGER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '14',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 79,
            'char' => 31,
          ),
          'docblock' => '**
     * Big integer abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 83,
          'char' => 6,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_BIT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '19',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 84,
            'char' => 24,
          ),
          'docblock' => '**
     * Bit abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 88,
          'char' => 6,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_BLOB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '11',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 89,
            'char' => 25,
          ),
          'docblock' => '**
     * Blob abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 93,
          'char' => 6,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_BOOLEAN',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 94,
            'char' => 27,
          ),
          'docblock' => '**
     * Bool abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 98,
          'char' => 6,
        ),
        11 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_CHAR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 99,
            'char' => 24,
          ),
          'docblock' => '**
     * Char abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 103,
          'char' => 6,
        ),
        12 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_DATE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 104,
            'char' => 24,
          ),
          'docblock' => '**
     * Date abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 108,
          'char' => 6,
        ),
        13 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_DATETIME',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 109,
            'char' => 28,
          ),
          'docblock' => '**
     * Datetime abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 113,
          'char' => 6,
        ),
        14 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_DECIMAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 114,
            'char' => 27,
          ),
          'docblock' => '**
     * Decimal abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 118,
          'char' => 6,
        ),
        15 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_DOUBLE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '9',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 119,
            'char' => 26,
          ),
          'docblock' => '**
     * Double abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 123,
          'char' => 6,
        ),
        16 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_ENUM',
          'default' => 
          array (
            'type' => 'int',
            'value' => '18',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 124,
            'char' => 25,
          ),
          'docblock' => '**
     * Enum abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 128,
          'char' => 6,
        ),
        17 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_FLOAT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '7',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 129,
            'char' => 25,
          ),
          'docblock' => '**
     * Float abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 133,
          'char' => 6,
        ),
        18 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_INTEGER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 134,
            'char' => 27,
          ),
          'docblock' => '**
     * Int abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 138,
          'char' => 6,
        ),
        19 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_JSON',
          'default' => 
          array (
            'type' => 'int',
            'value' => '15',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 139,
            'char' => 25,
          ),
          'docblock' => '**
     * Json abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 143,
          'char' => 6,
        ),
        20 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_JSONB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '16',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 144,
            'char' => 26,
          ),
          'docblock' => '**
     * Jsonb abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 148,
          'char' => 6,
        ),
        21 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_LONGBLOB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '13',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 149,
            'char' => 29,
          ),
          'docblock' => '**
     * Longblob abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 153,
          'char' => 6,
        ),
        22 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_LONGTEXT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '24',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 154,
            'char' => 29,
          ),
          'docblock' => '**
     * Longtext abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 158,
          'char' => 6,
        ),
        23 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_MEDIUMBLOB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '12',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 159,
            'char' => 31,
          ),
          'docblock' => '**
     * Mediumblob abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 163,
          'char' => 6,
        ),
        24 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_MEDIUMINTEGER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '21',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 164,
            'char' => 34,
          ),
          'docblock' => '**
     * Mediumintegerr abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 168,
          'char' => 6,
        ),
        25 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_MEDIUMTEXT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '23',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 169,
            'char' => 31,
          ),
          'docblock' => '**
     * Mediumtext abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 173,
          'char' => 6,
        ),
        26 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_SMALLINTEGER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '22',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 174,
            'char' => 33,
          ),
          'docblock' => '**
     * Smallint abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 178,
          'char' => 6,
        ),
        27 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TEXT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 179,
            'char' => 24,
          ),
          'docblock' => '**
     * Text abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 183,
          'char' => 6,
        ),
        28 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TIME',
          'default' => 
          array (
            'type' => 'int',
            'value' => '20',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 184,
            'char' => 25,
          ),
          'docblock' => '**
     * Time abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 188,
          'char' => 6,
        ),
        29 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TIMESTAMP',
          'default' => 
          array (
            'type' => 'int',
            'value' => '17',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 189,
            'char' => 30,
          ),
          'docblock' => '**
     * Timestamp abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 193,
          'char' => 6,
        ),
        30 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TINYBLOB',
          'default' => 
          array (
            'type' => 'int',
            'value' => '10',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 194,
            'char' => 29,
          ),
          'docblock' => '**
     * Tinyblob abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 198,
          'char' => 6,
        ),
        31 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TINYINTEGER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '26',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 199,
            'char' => 32,
          ),
          'docblock' => '**
     * Tinyint abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 203,
          'char' => 6,
        ),
        32 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_TINYTEXT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '25',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 204,
            'char' => 29,
          ),
          'docblock' => '**
     * Tinytext abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 208,
          'char' => 6,
        ),
        33 => 
        array (
          'type' => 'const',
          'name' => 'TYPE_VARCHAR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Db/Column.zep',
            'line' => 209,
            'char' => 27,
          ),
          'docblock' => '**
     * Varchar abstract data type
     *',
          'file' => '/app/phalcon/Db/Column.zep',
          'line' => 215,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Db/Column.zep',
      'line' => 39,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Column.zep',
    'line' => 39,
    'char' => 5,
  ),
);