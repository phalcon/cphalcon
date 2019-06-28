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
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Dialect',
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\Dialect',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\Column',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\Exception',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\IndexInterface',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\ColumnInterface',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 17,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\ReferenceInterface',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 18,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\DialectInterface',
        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
        'line' => 19,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Generates database specific SQL for the PostgreSQL RDBMS
 *',
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Postgresql',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Dialect',
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
          'name' => 'escapeChar',
          'default' => 
          array (
            'type' => 'string',
            'value' => '\\"',
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 29,
            'char' => 30,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 33,
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
          'name' => 'addColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 34,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 34,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 34,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 34,
              'char' => 94,
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
                  'variable' => 'columnDefinition',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 36,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 37,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 37,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 39,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnDefinition',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 39,
                      'char' => 37,
                    ),
                    'name' => 'getColumnDefinition',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 39,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 39,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 39,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 39,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 41,
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
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 41,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 41,
                          'char' => 39,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 41,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 41,
                            'char' => 62,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 41,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 41,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 41,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 41,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' ADD COLUMN ',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 41,
                      'char' => 90,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 41,
                    'char' => 90,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 41,
                  'char' => 90,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 42,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 42,
                          'char' => 22,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'column',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 42,
                            'char' => 31,
                          ),
                          'name' => 'getName',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 42,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 42,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '\\" ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 42,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 42,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnDefinition',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 42,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 42,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 42,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 44,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 44,
                  'char' => 19,
                ),
                'name' => 'hasDefault',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 44,
                'char' => 33,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' DEFAULT ',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 45,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 45,
                            'char' => 40,
                          ),
                          'name' => 'castDefault',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 45,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 45,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 45,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 45,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 45,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 48,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 48,
                  'char' => 19,
                ),
                'name' => 'isNotNull',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 48,
                'char' => 32,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ' NOT NULL',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 49,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 49,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 50,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 52,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 52,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 53,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to add a column to a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 34,
          'last-line' => 57,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addForeignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 58,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 58,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'reference',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ReferenceInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 58,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 58,
              'char' => 104,
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
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 60,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 60,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 61,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 61,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 63,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 63,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 63,
                          'char' => 39,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 63,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 63,
                            'char' => 62,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 63,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 63,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 63,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 63,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' ADD',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 63,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 63,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 63,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 65,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'reference',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 65,
                  'char' => 22,
                ),
                'name' => 'getName',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 65,
                'char' => 33,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => ' CONSTRAINT \\"',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 66,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 66,
                              'char' => 50,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 66,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 66,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 66,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 66,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 66,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 69,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' FOREIGN KEY (',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 69,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 69,
                                    'char' => 41,
                                  ),
                                  'name' => 'getColumnList',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'reference',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 69,
                                          'char' => 66,
                                        ),
                                        'name' => 'getColumns',
                                        'call-type' => 1,
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 69,
                                        'char' => 79,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 69,
                                      'char' => 79,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 69,
                                  'char' => 81,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 69,
                                'char' => 81,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ')',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 70,
                                'char' => 18,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 70,
                              'char' => 18,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' REFERENCES \\"',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 70,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 70,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 70,
                              'char' => 47,
                            ),
                            'name' => 'getReferencedTable',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 70,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 70,
                          'char' => 69,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\" (',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 70,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 70,
                        'char' => 76,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 70,
                          'char' => 83,
                        ),
                        'name' => 'getColumnList',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'reference',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 70,
                                'char' => 108,
                              ),
                              'name' => 'getReferencedColumns',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 70,
                              'char' => 131,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 70,
                            'char' => 131,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 70,
                        'char' => 133,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 70,
                      'char' => 133,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 70,
                      'char' => 136,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 70,
                    'char' => 136,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 70,
                  'char' => 136,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 72,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'onDelete',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reference',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 72,
                      'char' => 34,
                    ),
                    'name' => 'getOnDelete',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 72,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 72,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 73,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'onDelete',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 73,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 73,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 73,
                'char' => 28,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ON DELETE ',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 74,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'onDelete',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 74,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 74,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 74,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 75,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 77,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'onUpdate',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reference',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 77,
                      'char' => 34,
                    ),
                    'name' => 'getOnUpdate',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 77,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 77,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 78,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'onUpdate',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 78,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 78,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 78,
                'char' => 28,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ON UPDATE ',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 79,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'onUpdate',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 79,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 79,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 79,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 82,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 82,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to add an index to a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 59,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 58,
          'last-line' => 87,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 88,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 88,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'IndexInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 88,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 88,
              'char' => 91,
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
                  'variable' => 'indexType',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 90,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 91,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 91,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 93,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 93,
                    'char' => 18,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 93,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'PRIMARY',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 93,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 93,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 94,
                      'char' => 25,
                    ),
                    'name' => 'addPrimaryKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tableName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 94,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 94,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 94,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 94,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 94,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 94,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 94,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 97,
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
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'CREATE',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 97,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 97,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 99,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'indexType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 99,
                      'char' => 31,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 99,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 99,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 100,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexType',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 100,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 100,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 100,
                'char' => 29,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 101,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'indexType',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 101,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 101,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 101,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 103,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' INDEX \\"',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 103,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'index',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 103,
                            'char' => 37,
                          ),
                          'name' => 'getName',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 103,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 103,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '\\" ON ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 103,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 103,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 103,
                        'char' => 64,
                      ),
                      'name' => 'prepareTable',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 103,
                            'char' => 87,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 103,
                          'char' => 87,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 103,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 103,
                          'char' => 99,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 103,
                      'char' => 100,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 103,
                    'char' => 100,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 103,
                  'char' => 100,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 105,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => ' (',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 105,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 105,
                          'char' => 29,
                        ),
                        'name' => 'getColumnList',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'index',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 105,
                                'char' => 50,
                              ),
                              'name' => 'getColumns',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 105,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 105,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 105,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 105,
                      'char' => 65,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 105,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 105,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 105,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 107,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 107,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to add an index to a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 89,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 88,
          'last-line' => 112,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPrimaryKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 113,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 113,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'IndexInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 113,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 113,
              'char' => 96,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'ALTER TABLE ',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 115,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 115,
                              'char' => 36,
                            ),
                            'name' => 'prepareTable',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'tableName',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 115,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 115,
                                'char' => 59,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'schemaName',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 115,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 115,
                                'char' => 71,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 115,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 115,
                          'char' => 73,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' ADD CONSTRAINT \\"',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 115,
                          'char' => 94,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 115,
                        'char' => 94,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tableName',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 115,
                        'char' => 106,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 115,
                      'char' => 106,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '_PRIMARY\\" PRIMARY KEY (',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 115,
                      'char' => 133,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 115,
                    'char' => 133,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 115,
                      'char' => 140,
                    ),
                    'name' => 'getColumnList',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'index',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 115,
                            'char' => 161,
                          ),
                          'name' => 'getColumns',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 115,
                          'char' => 174,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 115,
                        'char' => 174,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 115,
                    'char' => 176,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 115,
                  'char' => 176,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => ')',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 115,
                  'char' => 179,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 115,
                'char' => 179,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to add the primary key to a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 113,
          'last-line' => 120,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createTable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 121,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 121,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 121,
              'char' => 89,
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
                  'variable' => 'temporary',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 64,
                ),
                6 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 123,
                  'char' => 71,
                ),
                7 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 22,
                ),
                8 => 
                array (
                  'variable' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 34,
                ),
                9 => 
                array (
                  'variable' => 'indexName',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 45,
                ),
                10 => 
                array (
                  'variable' => 'indexType',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 56,
                ),
                11 => 
                array (
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 66,
                ),
                12 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 124,
                  'char' => 76,
                ),
                13 => 
                array (
                  'variable' => 'columnDefinition',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 125,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 126,
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
                  'variable' => 'createLines',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 126,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'primaryColumns',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 126,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 127,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'indexSql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 127,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'indexSqlAfterCreate',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 127,
                  'char' => 45,
                ),
                2 => 
                array (
                  'variable' => 'columnLine',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 127,
                  'char' => 57,
                ),
                3 => 
                array (
                  'variable' => 'referenceSql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 127,
                  'char' => 71,
                ),
                4 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 127,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 129,
              'char' => 10,
            ),
            3 => 
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
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 129,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 129,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 129,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 129,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 129,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 129,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 129,
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
                          'value' => 'The index \'columns\' is required in the definition array',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 132,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 132,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 132,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 135,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'table',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 135,
                      'char' => 26,
                    ),
                    'name' => 'prepareTable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tableName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 135,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 135,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 135,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 135,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 135,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 135,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 137,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'temporary',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 137,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 137,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 138,
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
                  'value' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 138,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 138,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 138,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 138,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 138,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fetch',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'temporary',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 139,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 139,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'temporary',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 139,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 139,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 139,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 140,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 145,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'temporary',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 145,
                'char' => 22,
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
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'CREATE TEMPORARY TABLE ',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 146,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 146,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 146,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' (\\n\\t',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 146,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 146,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 146,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 147,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'CREATE TABLE ',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 148,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 148,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 148,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' (\\n\\t',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 148,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 148,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 148,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 149,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 151,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'createLines',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 151,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 151,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 152,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'primaryColumns',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 152,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 152,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 154,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 154,
                'char' => 31,
              ),
              'value' => 'column',
              'reverse' => 0,
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
                      'variable' => 'columnDefinition',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 155,
                          'char' => 41,
                        ),
                        'name' => 'getColumnDefinition',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 155,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 155,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 155,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 155,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 156,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'columnLine',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 156,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 156,
                                'char' => 42,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 156,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 156,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\" ',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 156,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 156,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnDefinition',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 156,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 156,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 156,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 161,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 161,
                      'char' => 23,
                    ),
                    'name' => 'hasDefault',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 161,
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
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnLine',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' DEFAULT ',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 162,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 162,
                                'char' => 51,
                              ),
                              'name' => 'castDefault',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 162,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 162,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 162,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 162,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 162,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 163,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 168,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 168,
                      'char' => 23,
                    ),
                    'name' => 'isNotNull',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 168,
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
                          'operator' => 'concat-assign',
                          'variable' => 'columnLine',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' NOT NULL',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 169,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 169,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 170,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 175,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 175,
                      'char' => 23,
                    ),
                    'name' => 'isPrimary',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 175,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'primaryColumns',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 176,
                              'char' => 47,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 176,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 176,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 177,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 179,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'createLines',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnLine',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 179,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 179,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 180,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 182,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'primaryColumns',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 182,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 182,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 182,
                'char' => 34,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'createLines',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'PRIMARY KEY (',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 183,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 183,
                              'char' => 54,
                            ),
                            'name' => 'getColumnList',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'primaryColumns',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 183,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 183,
                                'char' => 83,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 183,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 183,
                          'char' => 85,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 183,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 183,
                        'char' => 88,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 183,
                      'char' => 88,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 184,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 189,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'indexSqlAfterCreate',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 189,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 189,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 191,
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
                  'value' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 191,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 191,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'indexes',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 191,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 191,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 191,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexes',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 192,
                    'char' => 34,
                  ),
                  'value' => 'index',
                  'reverse' => 0,
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
                          'variable' => 'indexName',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 193,
                              'char' => 39,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 193,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 193,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 194,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'indexType',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 194,
                              'char' => 39,
                            ),
                            'name' => 'getType',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 194,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 194,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 195,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'indexSql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 195,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 195,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 200,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'indexName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 200,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'PRIMARY',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 200,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 200,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'indexSql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'CONSTRAINT \\"PRIMARY\\" PRIMARY KEY (',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 201,
                                    'char' => 73,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 201,
                                      'char' => 80,
                                    ),
                                    'name' => 'getColumnList',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'index',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 201,
                                            'char' => 101,
                                          ),
                                          'name' => 'getColumns',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 201,
                                          'char' => 114,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 201,
                                        'char' => 114,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 201,
                                    'char' => 116,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 201,
                                  'char' => 116,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ')',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 201,
                                  'char' => 119,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 201,
                                'char' => 119,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 201,
                              'char' => 119,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 202,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'not',
                            'left' => 
                            array (
                              'type' => 'empty',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'indexType',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 203,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 203,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 203,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'indexSql',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'concat',
                                              'left' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'CONSTRAINT \\"',
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 204,
                                                'char' => 54,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'indexName',
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 204,
                                                'char' => 66,
                                              ),
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 204,
                                              'char' => 66,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '\\" ',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 204,
                                              'char' => 72,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 204,
                                            'char' => 72,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'indexType',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 204,
                                            'char' => 84,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 204,
                                          'char' => 84,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ' (',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 204,
                                          'char' => 89,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 204,
                                        'char' => 89,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 204,
                                          'char' => 96,
                                        ),
                                        'name' => 'getColumnList',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'index',
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 204,
                                                'char' => 117,
                                              ),
                                              'name' => 'getColumns',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 204,
                                              'char' => 130,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 204,
                                            'char' => 130,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 204,
                                        'char' => 132,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 204,
                                      'char' => 132,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 204,
                                      'char' => 135,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 204,
                                    'char' => 135,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 204,
                                  'char' => 135,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 205,
                              'char' => 21,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'indexSqlAfterCreate',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'CREATE INDEX \\"',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 206,
                                          'char' => 67,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'index',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 206,
                                            'char' => 75,
                                          ),
                                          'name' => 'getName',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 206,
                                          'char' => 86,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 206,
                                        'char' => 86,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\" ON ',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 206,
                                        'char' => 95,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 206,
                                      'char' => 95,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 206,
                                        'char' => 102,
                                      ),
                                      'name' => 'prepareTable',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'tableName',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 206,
                                            'char' => 125,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 206,
                                          'char' => 125,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'schemaName',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 206,
                                            'char' => 137,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 206,
                                          'char' => 137,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 206,
                                      'char' => 138,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 206,
                                    'char' => 138,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 206,
                                  'char' => 138,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 208,
                              'char' => 27,
                            ),
                            1 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'indexSqlAfterCreate',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ' (',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 208,
                                        'char' => 54,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 208,
                                          'char' => 61,
                                        ),
                                        'name' => 'getColumnList',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'index',
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 208,
                                                'char' => 82,
                                              ),
                                              'name' => 'getColumns',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 208,
                                              'char' => 95,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 208,
                                            'char' => 95,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 208,
                                        'char' => 97,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 208,
                                      'char' => 97,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ');',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 208,
                                      'char' => 101,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 208,
                                    'char' => 101,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 208,
                                  'char' => 101,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 209,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 210,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 212,
                      'char' => 18,
                    ),
                    4 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexSql',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 212,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 212,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 212,
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'createLines',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'indexSql',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 213,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 213,
                              'char' => 49,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 214,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 215,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 216,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 221,
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
                  'value' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 221,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 221,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'references',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 221,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 221,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 221,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'references',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 222,
                    'char' => 41,
                  ),
                  'value' => 'reference',
                  'reverse' => 0,
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
                          'variable' => 'referenceSql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'CONSTRAINT \\"',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 223,
                                    'char' => 50,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'reference',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 223,
                                      'char' => 62,
                                    ),
                                    'name' => 'getName',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 223,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 223,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\" FOREIGN KEY (',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 223,
                                  'char' => 92,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 223,
                                'char' => 92,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 223,
                                  'char' => 99,
                                ),
                                'name' => 'getColumnList',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'reference',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 223,
                                        'char' => 124,
                                      ),
                                      'name' => 'getColumns',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 223,
                                      'char' => 137,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 223,
                                    'char' => 137,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 223,
                                'char' => 139,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 223,
                              'char' => 139,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') REFERENCES ',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 223,
                              'char' => 154,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 223,
                            'char' => 154,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 223,
                          'char' => 154,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 225,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'referenceSql',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 225,
                              'char' => 41,
                            ),
                            'name' => 'prepareTable',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'reference',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 226,
                                    'char' => 31,
                                  ),
                                  'name' => 'getReferencedTable',
                                  'call-type' => 1,
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 226,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 226,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'schemaName',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 228,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 228,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 228,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 228,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 230,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'referenceSql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => ' (',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 230,
                                'char' => 39,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 230,
                                  'char' => 46,
                                ),
                                'name' => 'getColumnList',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'reference',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 230,
                                        'char' => 71,
                                      ),
                                      'name' => 'getReferencedColumns',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 230,
                                      'char' => 94,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 230,
                                    'char' => 94,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 230,
                                'char' => 96,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 230,
                              'char' => 96,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ')',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 230,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 230,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 230,
                          'char' => 99,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 232,
                      'char' => 19,
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
                          'variable' => 'onDelete',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 232,
                              'char' => 42,
                            ),
                            'name' => 'getOnDelete',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 232,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 232,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 233,
                      'char' => 18,
                    ),
                    4 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'onDelete',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 233,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 233,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 233,
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
                              'operator' => 'concat-assign',
                              'variable' => 'referenceSql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ON DELETE ',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 234,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onDelete',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 234,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 234,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 234,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 235,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 237,
                      'char' => 19,
                    ),
                    5 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'onUpdate',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 237,
                              'char' => 42,
                            ),
                            'name' => 'getOnUpdate',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 237,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 237,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 238,
                      'char' => 18,
                    ),
                    6 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'onUpdate',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 238,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 238,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 238,
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
                              'operator' => 'concat-assign',
                              'variable' => 'referenceSql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ON UPDATE ',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 239,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onUpdate',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 239,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 239,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 239,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 240,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 242,
                      'char' => 19,
                    ),
                    7 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'createLines',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'referenceSql',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 242,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 242,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 243,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 246,
              'char' => 11,
            ),
            15 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'join',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => ',\\n\\t',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 246,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 246,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'createLines',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 246,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 246,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 246,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\\n)',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 246,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 246,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 246,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 247,
              'char' => 10,
            ),
            16 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 247,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 247,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 247,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 247,
                'char' => 38,
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
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 248,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 248,
                            'char' => 32,
                          ),
                          'name' => 'getTableOptions',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 248,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 248,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 248,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 248,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 248,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 250,
              'char' => 11,
            ),
            17 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => ';',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 250,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'indexSqlAfterCreate',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 250,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 250,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 250,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 252,
              'char' => 14,
            ),
            18 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 252,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 253,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to create a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 121,
          'last-line' => 257,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 258,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 258,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 258,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 258,
              'char' => 93,
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
                  'variable' => 'viewSql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 260,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 262,
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
                      'value' => 'viewSql',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 262,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 262,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'sql',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 262,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 262,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 262,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 262,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 262,
                'char' => 53,
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
                          'value' => 'The index \'sql\' is required in the definition array',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 265,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 265,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 265,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 266,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 268,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'CREATE VIEW ',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 268,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 268,
                        'char' => 36,
                      ),
                      'name' => 'prepareTable',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'viewName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 268,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 268,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 268,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 268,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 268,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 268,
                    'char' => 72,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => ' AS ',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 268,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 268,
                  'char' => 79,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'viewSql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 268,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 268,
                'char' => 88,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 269,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to create a view
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 259,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 259,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 258,
          'last-line' => 279,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeColumns',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 280,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 280,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 280,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schema',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 282,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 282,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 282,
                'char' => 28,
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
                      'variable' => 'schema',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 283,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 283,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 284,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 286,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN \'PRI\' ELSE \'\' END AS Key, CASE WHEN c.data_type LIKE \'%int%\' AND c.column_default LIKE \'%nextval%\' THEN \'auto_increment\' ELSE \'\' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type=\'PRIMARY KEY\') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema=\'',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 286,
                        'char' => 923,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 286,
                        'char' => 932,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 286,
                      'char' => 932,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\' AND c.table_name=\'',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 286,
                      'char' => 955,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 286,
                    'char' => 955,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 286,
                    'char' => 963,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 286,
                  'char' => 963,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' ORDER BY c.ordinal_position',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 286,
                  'char' => 994,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 286,
                'char' => 994,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 287,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL describing a table
     *
     * ```php
     * print_r(
     *     $dialect->describeColumns("posts")
     * );
     * ```
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 281,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 281,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 280,
          'last-line' => 291,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeIndexes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 292,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 292,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 292,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = \'r\' AND t.relname = \'',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 294,
                    'char' => 314,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 294,
                    'char' => 322,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 294,
                  'char' => 322,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' ORDER BY t.relname, i.relname;',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 294,
                  'char' => 356,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 294,
                'char' => 356,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 295,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to query indexes on a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 293,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 293,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 292,
          'last-line' => 299,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeReferences',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 300,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 300,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 300,
              'char' => 75,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schema',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 302,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 302,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 302,
                'char' => 28,
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
                      'variable' => 'schema',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 303,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 303,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 304,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 306,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = \'FOREIGN KEY\' WHERE constraint_type = \'FOREIGN KEY\' AND tc.table_schema = \'',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 306,
                        'char' => 854,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 306,
                        'char' => 863,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 306,
                      'char' => 863,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\' AND tc.table_name=\'',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 306,
                      'char' => 887,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 306,
                    'char' => 887,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 306,
                    'char' => 895,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 306,
                  'char' => 895,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 306,
                  'char' => 898,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 306,
                'char' => 898,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 307,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to query foreign keys on a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 301,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 301,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 300,
          'last-line' => 311,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 312,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 312,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'columnName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 312,
              'char' => 89,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 314,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 314,
                          'char' => 36,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 314,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 314,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 314,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 314,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 314,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 314,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP COLUMN \\"',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 314,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 314,
                    'char' => 91,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columnName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 314,
                    'char' => 104,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 314,
                  'char' => 104,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\\"',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 314,
                  'char' => 108,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 314,
                'char' => 108,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 315,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to delete a column from a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 313,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 313,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 312,
          'last-line' => 319,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropForeignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 320,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 320,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'referenceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 320,
              'char' => 96,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 322,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 322,
                          'char' => 36,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 322,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 322,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 322,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 322,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 322,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 322,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP CONSTRAINT \\"',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 322,
                      'char' => 95,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 322,
                    'char' => 95,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referenceName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 322,
                    'char' => 111,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 322,
                  'char' => 111,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\\"',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 322,
                  'char' => 115,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 322,
                'char' => 115,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 323,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to delete a foreign key from a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 321,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 321,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 320,
          'last-line' => 327,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 328,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 328,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'indexName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 328,
              'char' => 87,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'DROP INDEX \\"',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 330,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 330,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 330,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\\"',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 330,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 330,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 331,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to delete an index from a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 329,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 329,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 328,
          'last-line' => 335,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropPrimaryKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 336,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 336,
              'char' => 73,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 338,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 338,
                          'char' => 36,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 338,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 338,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 338,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 338,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 338,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 338,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP CONSTRAINT \\"',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 338,
                      'char' => 95,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 338,
                    'char' => 95,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tableName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 338,
                    'char' => 107,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 338,
                  'char' => 107,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '_PRIMARY\\"',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 338,
                  'char' => 119,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 338,
                'char' => 119,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 339,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to delete primary key from a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 337,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 337,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 336,
          'last-line' => 343,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropTable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 344,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 344,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 344,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ifExists',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 344,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 344,
              'char' => 97,
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
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 346,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 348,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'table',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 348,
                      'char' => 26,
                    ),
                    'name' => 'prepareTable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tableName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 348,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 348,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 348,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 348,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 348,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 348,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 350,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 350,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'DROP TABLE IF EXISTS ',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 351,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'table',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 351,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 351,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 352,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 354,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'DROP TABLE ',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 354,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 354,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 354,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 355,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to drop a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 345,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 345,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 344,
          'last-line' => 359,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 360,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 360,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 360,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ifExists',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 360,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 360,
              'char' => 95,
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
                  'variable' => 'view',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 362,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 364,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'view',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 364,
                      'char' => 25,
                    ),
                    'name' => 'prepareTable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'viewName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 364,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 364,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 364,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 364,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 364,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 364,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 366,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 366,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'DROP VIEW IF EXISTS ',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 367,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'view',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 367,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 367,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 368,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 370,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'DROP VIEW ',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 370,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'view',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 370,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 370,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 371,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to drop a view
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 361,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 361,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 360,
          'last-line' => 375,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnDefinition',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 376,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 376,
              'char' => 65,
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
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 378,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'columnSql',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 378,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'typeValues',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 378,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 380,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnSql',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 380,
                      'char' => 31,
                    ),
                    'name' => 'checkColumnTypeSql',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 380,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 380,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 380,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 380,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 381,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 381,
                      'char' => 31,
                    ),
                    'name' => 'checkColumnType',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 381,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 381,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 381,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 381,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 383,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnType',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 383,
                'char' => 27,
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
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 385,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BIGINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 385,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 385,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 386,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 386,
                        'char' => 36,
                      ),
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
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 387,
                              'char' => 31,
                            ),
                            'name' => 'isAutoIncrement',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 387,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'BIGSERIAL',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 388,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 388,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 389,
                              'char' => 21,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'BIGINT',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 390,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 390,
                                  'char' => 47,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 391,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 392,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 394,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 396,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 396,
                  'char' => 16,
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
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 396,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BOOLEAN',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 396,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 396,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 397,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 397,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'BOOLEAN',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 398,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 398,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 399,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 401,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 403,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 403,
                  'char' => 16,
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
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 403,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_CHAR',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 403,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 403,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 404,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 404,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'CHARACTER',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 405,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 405,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 406,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 408,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnSql',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 408,
                              'char' => 38,
                            ),
                            'name' => 'getColumnSize',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 408,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 408,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 408,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 408,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 410,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 412,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 412,
                  'char' => 16,
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
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 412,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATE',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 412,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 412,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 413,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 413,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'DATE',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 414,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 414,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 415,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 417,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 419,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 419,
                  'char' => 16,
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
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 419,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATETIME',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 419,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 419,
                    'char' => 39,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 420,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 420,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'TIMESTAMP',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 421,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 421,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 422,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 423,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 425,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 425,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 425,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DECIMAL',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 425,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 425,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 426,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 426,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'NUMERIC',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 427,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 427,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 428,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 430,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnSql',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 430,
                              'char' => 38,
                            ),
                            'name' => 'getColumnSizeAndScale',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 430,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 430,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 430,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 430,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 432,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 434,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 434,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 434,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_FLOAT',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 434,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 434,
                    'char' => 36,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 435,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 435,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'FLOAT',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 436,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 436,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 437,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 439,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 441,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 441,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 441,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_INTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 441,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 441,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 442,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 442,
                        'char' => 36,
                      ),
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
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 443,
                              'char' => 31,
                            ),
                            'name' => 'isAutoIncrement',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 443,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'SERIAL',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 444,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 444,
                                  'char' => 47,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 445,
                              'char' => 21,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'INT',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 446,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 446,
                                  'char' => 44,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 447,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 448,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 450,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 452,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 452,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 452,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_JSON',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 452,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 452,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 453,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 453,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'JSON',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 454,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 454,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 455,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 457,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 459,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 459,
                  'char' => 16,
                ),
                9 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 459,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_JSONB',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 459,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 459,
                    'char' => 36,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 460,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 460,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'JSONB',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 461,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 461,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 462,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 464,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 466,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 466,
                  'char' => 16,
                ),
                10 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 466,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TIMESTAMP',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 466,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 466,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 467,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 467,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'TIMESTAMP',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 468,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 468,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 469,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 471,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 473,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 473,
                  'char' => 16,
                ),
                11 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 473,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TEXT',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 473,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 473,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 474,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 474,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'TEXT',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 475,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 475,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 476,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 478,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 480,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 480,
                  'char' => 16,
                ),
                12 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 480,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_VARCHAR',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 480,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 480,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnSql',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 481,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 481,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'CHARACTER VARYING',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 482,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 482,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 483,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 485,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnSql',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 485,
                              'char' => 38,
                            ),
                            'name' => 'getColumnSize',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 485,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 485,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 485,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 485,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 487,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 489,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 489,
                  'char' => 19,
                ),
                13 => 
                array (
                  'type' => 'default',
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
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnSql',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 490,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 490,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 490,
                        'char' => 45,
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Unrecognized PostgreSQL data type at column ',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 492,
                                    'char' => 70,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'column',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 492,
                                      'char' => 79,
                                    ),
                                    'name' => 'getName',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 493,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 493,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 493,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 493,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 494,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 496,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'typeValues',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 496,
                              'char' => 41,
                            ),
                            'name' => 'getTypeValues',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 496,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 496,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 497,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'typeValues',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 497,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 497,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 497,
                        'char' => 38,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'typeValues',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 498,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 498,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 498,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 498,
                            'char' => 51,
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
                                  'variable' => 'value',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 499,
                                  'char' => 34,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 500,
                              'char' => 30,
                            ),
                            1 => 
                            array (
                              'type' => 'declare',
                              'data-type' => 'string',
                              'variables' => 
                              array (
                                0 => 
                                array (
                                  'variable' => 'valueSql',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 500,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 502,
                              'char' => 27,
                            ),
                            2 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'valueSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 502,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 502,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 504,
                              'char' => 27,
                            ),
                            3 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'typeValues',
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 504,
                                'char' => 49,
                              ),
                              'value' => 'value',
                              'reverse' => 0,
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
                                      'operator' => 'concat-assign',
                                      'variable' => 'valueSql',
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\'',
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 505,
                                            'char' => 46,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'addcslashes',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'value',
                                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                  'line' => 505,
                                                  'char' => 65,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 505,
                                                'char' => 65,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '\\\'',
                                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                  'line' => 505,
                                                  'char' => 69,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                                'line' => 505,
                                                'char' => 69,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 505,
                                            'char' => 71,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 505,
                                          'char' => 71,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\', ',
                                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                          'line' => 505,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 505,
                                        'char' => 76,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 505,
                                      'char' => 76,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 506,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 508,
                              'char' => 27,
                            ),
                            4 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '(',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 508,
                                        'char' => 43,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'substr',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'valueSql',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 508,
                                              'char' => 60,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 508,
                                            'char' => 60,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '0',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 508,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 508,
                                            'char' => 63,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '-2',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 508,
                                              'char' => 67,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 508,
                                            'char' => 67,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 508,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 508,
                                      'char' => 69,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 508,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 508,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 508,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 509,
                              'char' => 21,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'columnSql',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '(\'',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 510,
                                        'char' => 44,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'addcslashes',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'typeValues',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 510,
                                              'char' => 68,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 510,
                                            'char' => 68,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '\\\'',
                                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                              'line' => 510,
                                              'char' => 72,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                            'line' => 510,
                                            'char' => 72,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 510,
                                        'char' => 74,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 510,
                                      'char' => 74,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\')',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 510,
                                      'char' => 78,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 510,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 510,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 511,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 512,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 513,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 513,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 515,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnSql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 515,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 516,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the column name in PostgreSQL
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 377,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 377,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 376,
          'last-line' => 526,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listTables',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 527,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 527,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schemaName',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 529,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 529,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 529,
                'char' => 32,
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
                      'variable' => 'schemaName',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 530,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 530,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 531,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 533,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'SELECT table_name FROM information_schema.tables WHERE table_schema = \'',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 533,
                    'char' => 88,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'schemaName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 533,
                    'char' => 101,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 533,
                  'char' => 101,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' ORDER BY table_name',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 533,
                  'char' => 124,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 533,
                'char' => 124,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 534,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * List all tables in database
     *
     * ```php
     * print_r(
     *     $dialect->listTables("blog")
     * );
     * ```
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 528,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 528,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 527,
          'last-line' => 538,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listViews',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 539,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 539,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schemaName',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 541,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 541,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 541,
                'char' => 32,
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
                      'variable' => 'schemaName',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 542,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 542,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 543,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 545,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'SELECT viewname AS view_name FROM pg_views WHERE schemaname = \'',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 545,
                    'char' => 80,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'schemaName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 545,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 545,
                  'char' => 93,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' ORDER BY view_name',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 545,
                  'char' => 115,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 545,
                'char' => 115,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 546,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates the SQL to list all views of a schema or user
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 540,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 540,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 539,
          'last-line' => 550,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'modifyColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 551,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 551,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 551,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 551,
              'char' => 97,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'currentColumn',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 551,
                'char' => 129,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 551,
                'char' => 137,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 551,
              'char' => 137,
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
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 553,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'columnDefinition',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 553,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 554,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 554,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 554,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'sqlAlterTable',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 554,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 556,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnDefinition',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 556,
                      'char' => 37,
                    ),
                    'name' => 'getColumnDefinition',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 556,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 556,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 556,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 556,
                  'char' => 65,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'sqlAlterTable',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'ALTER TABLE ',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 557,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 557,
                        'char' => 49,
                      ),
                      'name' => 'prepareTable',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 557,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 557,
                          'char' => 72,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 557,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 557,
                          'char' => 84,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 557,
                      'char' => 85,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 557,
                    'char' => 85,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 557,
                  'char' => 85,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 559,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 559,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 559,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 559,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 559,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'currentColumn',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'column',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 560,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 560,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 561,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 564,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'column',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 564,
                    'char' => 19,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 564,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 564,
                    'char' => 48,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 564,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 564,
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
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlAlterTable',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 565,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' RENAME COLUMN \\"',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 565,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 565,
                                'char' => 57,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'currentColumn',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 565,
                                  'char' => 73,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 565,
                                'char' => 84,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 565,
                              'char' => 84,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" TO \\"',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 565,
                              'char' => 95,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 565,
                            'char' => 95,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 565,
                              'char' => 104,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 565,
                            'char' => 115,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 565,
                          'char' => 115,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\";',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 565,
                          'char' => 120,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 565,
                        'char' => 120,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 565,
                      'char' => 120,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 566,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 569,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'column',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 569,
                    'char' => 19,
                  ),
                  'name' => 'getType',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 569,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 569,
                    'char' => 48,
                  ),
                  'name' => 'getType',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 569,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 569,
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
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlAlterTable',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 570,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ALTER COLUMN \\"',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 570,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 570,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 570,
                                  'char' => 65,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 570,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 570,
                              'char' => 76,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" TYPE ',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 570,
                              'char' => 87,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 570,
                            'char' => 87,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnDefinition',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 570,
                            'char' => 106,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 570,
                          'char' => 106,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ';',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 570,
                          'char' => 109,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 570,
                        'char' => 109,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 570,
                      'char' => 109,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 571,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 574,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'column',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 574,
                    'char' => 19,
                  ),
                  'name' => 'isNotNull',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 574,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 574,
                    'char' => 50,
                  ),
                  'name' => 'isNotNull',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 574,
                  'char' => 63,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 574,
                'char' => 63,
              ),
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
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 575,
                      'char' => 23,
                    ),
                    'name' => 'isNotNull',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 575,
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
                          'operator' => 'concat-assign',
                          'variable' => 'sql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlAlterTable',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 576,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ALTER COLUMN \\"',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 576,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 576,
                                'char' => 60,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 576,
                                  'char' => 69,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 576,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 576,
                              'char' => 80,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" SET NOT NULL;',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 576,
                              'char' => 98,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 576,
                            'char' => 98,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 576,
                          'char' => 98,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 577,
                      'char' => 13,
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
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'sql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlAlterTable',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 578,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ALTER COLUMN \\"',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 578,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 578,
                                'char' => 60,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 578,
                                  'char' => 69,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 578,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 578,
                              'char' => 80,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" DROP NOT NULL;',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 578,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 578,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 578,
                          'char' => 99,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 579,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 580,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 583,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'column',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 583,
                    'char' => 19,
                  ),
                  'name' => 'getDefault',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 583,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 583,
                    'char' => 51,
                  ),
                  'name' => 'getDefault',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 583,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 583,
                'char' => 65,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 584,
                          'char' => 29,
                        ),
                        'name' => 'getDefault',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 584,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 584,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'currentColumn',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 584,
                            'char' => 67,
                          ),
                          'name' => 'getDefault',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 584,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 584,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 584,
                      'char' => 81,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 584,
                    'char' => 81,
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
                          'operator' => 'concat-assign',
                          'variable' => 'sql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlAlterTable',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 585,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ALTER COLUMN \\"',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 585,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 585,
                                'char' => 60,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 585,
                                  'char' => 69,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 585,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 585,
                              'char' => 80,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" DROP DEFAULT;',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 585,
                              'char' => 98,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 585,
                            'char' => 98,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 585,
                          'char' => 98,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 586,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 588,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 588,
                      'char' => 23,
                    ),
                    'name' => 'hasDefault',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 588,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'defaultValue',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 589,
                              'char' => 41,
                            ),
                            'name' => 'castDefault',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 589,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 589,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 589,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 589,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 591,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'memstr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'strtoupper',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'columnDefinition',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 591,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 591,
                                  'char' => 54,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 591,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 591,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'BOOLEAN',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 591,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 591,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 591,
                        'char' => 66,
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
                              'operator' => 'concat-assign',
                              'variable' => 'sql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' ALTER COLUMN \\"',
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 592,
                                      'char' => 48,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'column',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 592,
                                        'char' => 57,
                                      ),
                                      'name' => 'getName',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 592,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 592,
                                    'char' => 68,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\\" SET DEFAULT ',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 592,
                                    'char' => 86,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 592,
                                  'char' => 86,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultValue',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 592,
                                  'char' => 100,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 592,
                                'char' => 100,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 592,
                              'char' => 100,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 593,
                          'char' => 17,
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
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'sql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'sqlAlterTable',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 594,
                                        'char' => 45,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ' ALTER COLUMN \\"',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 594,
                                        'char' => 64,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 594,
                                      'char' => 64,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'column',
                                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                        'line' => 594,
                                        'char' => 73,
                                      ),
                                      'name' => 'getName',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                      'line' => 594,
                                      'char' => 84,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 594,
                                    'char' => 84,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\\" SET DEFAULT ',
                                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                    'line' => 594,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 594,
                                  'char' => 102,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultValue',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 594,
                                  'char' => 116,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 594,
                                'char' => 116,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 594,
                              'char' => 116,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 595,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 596,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 597,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 599,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 599,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 600,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to modify a column in a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 552,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 552,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 551,
          'last-line' => 605,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sharedLock',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 606,
              'char' => 48,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sqlQuery',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 608,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 609,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a SQL modified a shared lock statement. For now this method
     * returns the original query
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 607,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 607,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 606,
          'last-line' => 619,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'tableExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 620,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 620,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 620,
              'char' => 76,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schemaName',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 622,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 622,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 622,
                'char' => 32,
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
                      'variable' => 'schemaName',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 623,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 623,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 624,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 626,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = \'',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 626,
                        'char' => 118,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemaName',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 626,
                        'char' => 131,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 626,
                      'char' => 131,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\' AND table_name=\'',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 626,
                      'char' => 152,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 626,
                    'char' => 152,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tableName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 626,
                    'char' => 164,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 626,
                  'char' => 164,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 626,
                  'char' => 167,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 626,
                'char' => 167,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 627,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL checking for the existence of a schema.table
     *
     * ```php
     * echo $dialect->tableExists("posts", "blog");
     *
     * echo $dialect->tableExists("posts");
     * ```
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 621,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 621,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 620,
          'last-line' => 631,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'tableOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 632,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 632,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 632,
              'char' => 69,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 634,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 635,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates the SQL to describe the table creation options
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 633,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 633,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 632,
          'last-line' => 639,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'truncateTable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 640,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 640,
              'char' => 72,
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
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 642,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 644,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 644,
                'char' => 23,
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
                      'variable' => 'table',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 645,
                          'char' => 30,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 645,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 645,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 645,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 645,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 645,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 645,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 646,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'table',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 647,
                          'char' => 30,
                        ),
                        'name' => 'prepareTable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableName',
                              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                              'line' => 647,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 647,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 647,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 647,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 648,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 650,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'TRUNCATE TABLE ',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 650,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 650,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 650,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 651,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to truncate a table
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 641,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 641,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 640,
          'last-line' => 655,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'viewExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 656,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 656,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 656,
              'char' => 74,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'schemaName',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 658,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 658,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 658,
                'char' => 32,
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
                      'variable' => 'schemaName',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'public',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 659,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 659,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 660,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 662,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname=\'',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 662,
                        'char' => 95,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'viewName',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 662,
                        'char' => 106,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 662,
                      'char' => 106,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\' AND schemaname=\'',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 662,
                      'char' => 127,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 662,
                    'char' => 127,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'schemaName',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 662,
                    'char' => 140,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 662,
                  'char' => 140,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 662,
                  'char' => 143,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 662,
                'char' => 143,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 663,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL checking for the existence of a schema.view
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 657,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 657,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 656,
          'last-line' => 665,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'castDefault',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 665,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 665,
              'char' => 60,
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
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 667,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'columnDefinition',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 667,
                  'char' => 43,
                ),
                2 => 
                array (
                  'variable' => 'columnType',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 667,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 668,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'preparedValue',
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 668,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 670,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'defaultValue',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 670,
                      'char' => 35,
                    ),
                    'name' => 'getDefault',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 670,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 670,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnDefinition',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 671,
                      'char' => 37,
                    ),
                    'name' => 'getColumnDefinition',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 671,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 671,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 671,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 671,
                  'char' => 65,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 672,
                      'char' => 33,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 672,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 672,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 674,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtoupper',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnDefinition',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 674,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 674,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 674,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 674,
                    'char' => 47,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'BOOLEAN',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 674,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 674,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 674,
                'char' => 58,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 675,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 676,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 678,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtoupper',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultValue',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 678,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 678,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 678,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 678,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'CURRENT_TIMESTAMP',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 678,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 678,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 678,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'CURRENT_TIMESTAMP',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 679,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 680,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 682,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'or',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'or',
                      'left' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnType',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 682,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 682,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'TYPE_INTEGER',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 682,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 682,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 682,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnType',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 683,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 683,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'TYPE_BIGINTEGER',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 683,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 683,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 683,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 683,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnType',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 684,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Column',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 684,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'TYPE_DECIMAL',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 684,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 684,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 684,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 684,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnType',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 685,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Column',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 685,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'TYPE_FLOAT',
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 685,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 685,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 685,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 685,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columnType',
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 686,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 686,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DOUBLE',
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 686,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                    'line' => 686,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 686,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 686,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'preparedValue',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultValue',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 687,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 687,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 687,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 688,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'preparedValue',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '\'',
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 689,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'addcslashes',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultValue',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 689,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 689,
                                'char' => 61,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\\'',
                                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                  'line' => 689,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                                'line' => 689,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                            'line' => 689,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 689,
                          'char' => 67,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\'',
                          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                          'line' => 689,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                        'line' => 689,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                      'line' => 689,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                  'line' => 690,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 692,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'preparedValue',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 692,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 693,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 666,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 666,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 665,
          'last-line' => 695,
          'char' => 22,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getTableOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 695,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 697,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
              'line' => 698,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
                'line' => 696,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
            'line' => 696,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
          'line' => 695,
          'last-line' => 699,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Dialect/Postgresql.zep',
    'line' => 24,
    'char' => 5,
  ),
);