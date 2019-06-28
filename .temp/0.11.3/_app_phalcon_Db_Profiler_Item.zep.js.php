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
    'file' => '/app/phalcon/Db/Profiler/Item.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Profiler',
    'file' => '/app/phalcon/Db/Profiler/Item.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class identifies each profile in a Phalcon\\Db\\Profiler
 *',
    'file' => '/app/phalcon/Db/Profiler/Item.zep',
    'line' => 16,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Item',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'finalTime',
          'docblock' => '**
     * Timestamp when the profile ended
     *
     * @var double
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 23,
              'char' => 30,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 23,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 29,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'initialTime',
          'docblock' => '**
     * Timestamp when the profile started
     *
     * @var double
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 30,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 30,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 36,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sqlBindTypes',
          'docblock' => '**
     * SQL bind types related to the profile
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 37,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 37,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 43,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sqlStatement',
          'docblock' => '**
     * SQL statement related to the profile
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 44,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 44,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 50,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sqlVariables',
          'docblock' => '**
     * SQL variables related to the profile
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 51,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 51,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 55,
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
          'name' => 'getTotalElapsedSeconds',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'sub',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Profiler/Item.zep',
                    'line' => 58,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'finalTime',
                    'file' => '/app/phalcon/Db/Profiler/Item.zep',
                    'line' => 58,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Db/Profiler/Item.zep',
                  'line' => 58,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Profiler/Item.zep',
                    'line' => 58,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'initialTime',
                    'file' => '/app/phalcon/Db/Profiler/Item.zep',
                    'line' => 58,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Profiler/Item.zep',
                  'line' => 58,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Db/Profiler/Item.zep',
                'line' => 58,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Db/Profiler/Item.zep',
              'line' => 59,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the total time in seconds spent by the profile
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Profiler/Item.zep',
                'line' => 57,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler/Item.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler/Item.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/Profiler/Item.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Profiler/Item.zep',
    'line' => 16,
    'char' => 5,
  ),
);