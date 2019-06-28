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
    'file' => '/app/phalcon/Db/Index.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/Index.zep',
    'line' => 41,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index
 *
 *```php
 * // Define new unique index
 * $index_unique = new \\Phalcon\\Db\\Index(
 *     \'column_UNIQUE\',
 *     [
 *         \'column\',
 *         \'column\',
 *     ],
 *     \'UNIQUE\'
 * );
 *
 * // Define new primary index
 * $index_primary = new \\Phalcon\\Db\\Index(
 *     \'PRIMARY\',
 *     [
 *         \'column\',
 *     ]
 * );
 *
 * // Add index to existing table
 * $connection->addIndex("robots", null, $index_unique);
 * $connection->addIndex("robots", null, $index_primary);
 *```
 *',
    'file' => '/app/phalcon/Db/Index.zep',
    'line' => 42,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Index',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'IndexInterface',
        'file' => '/app/phalcon/Db/Index.zep',
        'line' => 43,
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
     * Index columns
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 49,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Db/Index.zep',
          'line' => 55,
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
     * Index name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 56,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Db/Index.zep',
          'line' => 62,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'docblock' => '**
     * Index type
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 63,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Db/Index.zep',
          'line' => 67,
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
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 68,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'columns',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 68,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 68,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 68,
              'char' => 77,
            ),
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
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 70,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 70,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 71,
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
                  'property' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 71,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 71,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 72,
              'char' => 11,
            ),
            2 => 
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
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 72,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 72,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Db\\Index constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Index.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Index.zep',
          'line' => 68,
          'last-line' => 77,
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
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 78,
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
                  'variable' => 'indexName',
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 80,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 80,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 80,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 82,
              'char' => 10,
            ),
            1 => 
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
                      'value' => 'indexName',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 82,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 82,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'name',
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 82,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 82,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 82,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 82,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 82,
                'char' => 50,
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
                          'file' => '/app/phalcon/Db/Index.zep',
                          'line' => 83,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 83,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 83,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 86,
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
                      'value' => 'columns',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 86,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 86,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 86,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 86,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 86,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 86,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 86,
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
                          'value' => 'columns parameter is required',
                          'file' => '/app/phalcon/Db/Index.zep',
                          'line' => 87,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 87,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 87,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 90,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'type',
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 90,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 90,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 90,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 90,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 90,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 90,
                'char' => 36,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'type',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Db/Index.zep',
                        'line' => 91,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 91,
                      'char' => 24,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 97,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Index',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'indexName',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 97,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 97,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 97,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 97,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Db/Index.zep',
                      'line' => 97,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Index.zep',
                    'line' => 97,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 97,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Db/Index.zep',
              'line' => 98,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Restore a Phalcon\\Db\\Index object from export
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
                  'value' => 'IndexInterface',
                  'file' => '/app/phalcon/Db/Index.zep',
                  'line' => 79,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Index.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Index.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Index.zep',
          'line' => 78,
          'last-line' => 99,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Db/Index.zep',
      'line' => 42,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Index.zep',
    'line' => 42,
    'char' => 5,
  ),
);