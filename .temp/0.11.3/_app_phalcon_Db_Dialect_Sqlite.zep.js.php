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
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Dialect',
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\Column',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 13,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\Exception',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\IndexInterface',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\Dialect',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 16,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\DialectInterface',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\ColumnInterface',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\ReferenceInterface',
        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
        'line' => 19,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Generates database specific SQL for the SQLite RDBMS
 *',
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Sqlite',
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
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 29,
            'char' => 30,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 34,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 36,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 37,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 39,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 39,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 39,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 39,
                            'char' => 62,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 39,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 39,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 39,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 39,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' ADD COLUMN ',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 39,
                      'char' => 90,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 39,
                    'char' => 90,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 39,
                  'char' => 90,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 41,
                          'char' => 22,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'column',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 41,
                            'char' => 31,
                          ),
                          'name' => 'getName',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 41,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 41,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '\\" ',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 41,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 41,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 41,
                        'char' => 55,
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
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 41,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 41,
                          'char' => 82,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 41,
                      'char' => 83,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 41,
                    'char' => 83,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 41,
                  'char' => 83,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 43,
              'char' => 10,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 43,
                  'char' => 19,
                ),
                'name' => 'hasDefault',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 43,
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
                      'operator' => 'assign',
                      'variable' => 'defaultValue',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 44,
                          'char' => 39,
                        ),
                        'name' => 'getDefault',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 44,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 44,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 46,
                  'char' => 14,
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
                                'value' => 'defaultValue',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 46,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 46,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 46,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 46,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'CURRENT_TIMESTAMP',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 46,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 46,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 46,
                    'char' => 68,
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
                            'value' => ' DEFAULT CURRENT_TIMESTAMP',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 47,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 47,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 48,
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
                                'type' => 'string',
                                'value' => ' DEFAULT \\"',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 49,
                                'char' => 39,
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
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 49,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 49,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\"',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 49,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 49,
                                    'char' => 69,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 49,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 49,
                              'char' => 71,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 49,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 49,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 49,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 50,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 53,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 53,
                  'char' => 19,
                ),
                'name' => 'isNotNull',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 53,
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
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 54,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 54,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 55,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 57,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 57,
                  'char' => 19,
                ),
                'name' => 'isAutoincrement',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 57,
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
                        'type' => 'string',
                        'value' => ' PRIMARY KEY AUTOINCREMENT',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 58,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 58,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 59,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 61,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 61,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 62,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 34,
          'last-line' => 66,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 67,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 67,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 67,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 67,
              'char' => 104,
            ),
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
                      'value' => 'Adding a foreign key constraint to an existing table is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 71,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 71,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 71,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 72,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 67,
          'last-line' => 76,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 77,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 77,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 77,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 77,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 79,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 80,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 80,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 82,
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
                  'variable' => 'indexType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 82,
                      'char' => 31,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 82,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 82,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 84,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexType',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 84,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 84,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 84,
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
                            'value' => 'CREATE ',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 85,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexType',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 85,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 85,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' INDEX ',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 85,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 85,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 85,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 86,
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
                        'type' => 'string',
                        'value' => 'CREATE INDEX ',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 87,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 87,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 90,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 90,
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
                                'type' => 'string',
                                'value' => '\\"',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 91,
                                'char' => 26,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schemaName',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 91,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 91,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\".\\"',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 91,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 91,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 91,
                              'char' => 55,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 91,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 91,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 91,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 91,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 91,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 92,
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
                            'value' => '\\"',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 93,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 93,
                              'char' => 34,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 93,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 93,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 93,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 93,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 93,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 96,
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
                            'type' => 'string',
                            'value' => ' ON \\"',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 96,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 96,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 96,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\" (',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 96,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 96,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 96,
                          'char' => 52,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 96,
                                'char' => 73,
                              ),
                              'name' => 'getColumns',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 96,
                              'char' => 86,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 96,
                            'char' => 86,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 96,
                        'char' => 88,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 96,
                      'char' => 88,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 96,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 96,
                    'char' => 91,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 96,
                  'char' => 91,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 98,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 98,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 99,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 77,
          'last-line' => 103,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 104,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 104,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 104,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 104,
              'char' => 96,
            ),
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
                      'value' => 'Adding a primary key after table has been created is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 108,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 108,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 108,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 109,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 104,
          'last-line' => 113,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 114,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 114,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 114,
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
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'temporary',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'createLines',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 60,
                ),
                5 => 
                array (
                  'variable' => 'columnLine',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 116,
                  'char' => 72,
                ),
                6 => 
                array (
                  'variable' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 19,
                ),
                7 => 
                array (
                  'variable' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 28,
                ),
                8 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 35,
                ),
                9 => 
                array (
                  'variable' => 'indexName',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 46,
                ),
                10 => 
                array (
                  'variable' => 'indexType',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 57,
                ),
                11 => 
                array (
                  'variable' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 69,
                ),
                12 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 117,
                  'char' => 80,
                ),
                13 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 118,
                  'char' => 25,
                ),
                14 => 
                array (
                  'variable' => 'referenceSql',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 118,
                  'char' => 39,
                ),
                15 => 
                array (
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 118,
                  'char' => 49,
                ),
                16 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 118,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 119,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hasPrimary',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 119,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 120,
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
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 120,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 122,
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
                  'variable' => 'table',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 122,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 122,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 122,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 122,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 122,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 122,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 122,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 124,
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
                  'variable' => 'temporary',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 124,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 124,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 125,
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
                  'value' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 125,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 125,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 125,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 125,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 125,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 126,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 126,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'temporary',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 126,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 126,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 126,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 129,
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
                      'value' => 'columns',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 129,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 129,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 129,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 129,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 129,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 132,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 132,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 132,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 138,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'temporary',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 138,
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
                          'type' => 'string',
                          'value' => 'CREATE TEMPORARY TABLE ',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 139,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'table',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 139,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 139,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 139,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 140,
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
                          'type' => 'string',
                          'value' => 'CREATE TABLE ',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 141,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'table',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 141,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 141,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 141,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 144,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sql',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => ' (\\n\\t',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 144,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 144,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 146,
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
                  'variable' => 'hasPrimary',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 146,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 146,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 147,
              'char' => 11,
            ),
            10 => 
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
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 147,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 147,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 149,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 149,
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
                              'value' => '`',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 150,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 150,
                                'char' => 41,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 150,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 150,
                            'char' => 52,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '` ',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 150,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 150,
                          'char' => 57,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 150,
                            'char' => 64,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 150,
                                'char' => 91,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 150,
                              'char' => 91,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 150,
                          'char' => 92,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 150,
                        'char' => 92,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 150,
                      'char' => 92,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 155,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'column',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 155,
                        'char' => 23,
                      ),
                      'name' => 'isPrimary',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 155,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hasPrimary',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 155,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 155,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 155,
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
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnLine',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' PRIMARY KEY',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 156,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 156,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 157,
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
                          'variable' => 'hasPrimary',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 157,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 157,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 158,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 163,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'column',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 163,
                        'char' => 23,
                      ),
                      'name' => 'isAutoIncrement',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 163,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hasPrimary',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 163,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 163,
                    'char' => 56,
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
                            'value' => ' AUTOINCREMENT',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 164,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 164,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 165,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 170,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 170,
                      'char' => 23,
                    ),
                    'name' => 'hasDefault',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 170,
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
                              'value' => 'column',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 171,
                              'char' => 43,
                            ),
                            'name' => 'getDefault',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 171,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 171,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 173,
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
                                    'value' => 'defaultValue',
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 173,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 173,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 173,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 173,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'CURRENT_TIMESTAMP',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 173,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 173,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 173,
                        'char' => 72,
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
                                'value' => ' DEFAULT CURRENT_TIMESTAMP',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 174,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 174,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 175,
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
                              'variable' => 'columnLine',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' DEFAULT \\"',
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 176,
                                    'char' => 50,
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
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 176,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 176,
                                        'char' => 76,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\"',
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 176,
                                          'char' => 80,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 176,
                                        'char' => 80,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 176,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 176,
                                  'char' => 82,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\"',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 176,
                                  'char' => 86,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 176,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 176,
                              'char' => 86,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 177,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 178,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 183,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 183,
                      'char' => 23,
                    ),
                    'name' => 'isNotNull',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 183,
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
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 184,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 184,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 185,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 187,
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
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 187,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 187,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 193,
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
                  'value' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 193,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 193,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'indexes',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 193,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 193,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 193,
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
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 194,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 195,
                              'char' => 39,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 195,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 195,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 196,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 196,
                              'char' => 39,
                            ),
                            'name' => 'getType',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 196,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 196,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 201,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 201,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'PRIMARY',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 201,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 201,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'hasPrimary',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 201,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 201,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 201,
                        'char' => 56,
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
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 202,
                                    'char' => 55,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 202,
                                      'char' => 62,
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
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 202,
                                            'char' => 83,
                                          ),
                                          'name' => 'getColumns',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 202,
                                          'char' => 96,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 202,
                                        'char' => 96,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 202,
                                    'char' => 98,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 202,
                                  'char' => 98,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ')',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 202,
                                  'char' => 101,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 202,
                                'char' => 101,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 202,
                              'char' => 101,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 203,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'not',
                              'left' => 
                              array (
                                'type' => 'empty',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'indexType',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 203,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 203,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 203,
                              'char' => 44,
                            ),
                            'right' => 
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
                                          'value' => 'indexType',
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 203,
                                          'char' => 73,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 203,
                                        'char' => 73,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 203,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 203,
                                  'char' => 74,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'UNIQUE',
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 203,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 203,
                                  'char' => 82,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 203,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 203,
                            'char' => 84,
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
                                        'value' => 'UNIQUE (',
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 204,
                                        'char' => 50,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 204,
                                          'char' => 57,
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
                                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                'line' => 204,
                                                'char' => 78,
                                              ),
                                              'name' => 'getColumns',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 204,
                                              'char' => 91,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 204,
                                            'char' => 91,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 204,
                                        'char' => 93,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 204,
                                      'char' => 93,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 204,
                                      'char' => 96,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 204,
                                    'char' => 96,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 204,
                                  'char' => 96,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 205,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 206,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 206,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 207,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 212,
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
                  'value' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 212,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 212,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'references',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 212,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 212,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 212,
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
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 213,
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
                                              'value' => 'CONSTRAINT `',
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 214,
                                              'char' => 49,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'reference',
                                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                'line' => 214,
                                                'char' => 61,
                                              ),
                                              'name' => 'getName',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 214,
                                              'char' => 72,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 214,
                                            'char' => 72,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '` FOREIGN KEY (',
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 214,
                                            'char' => 90,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 214,
                                          'char' => 90,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 214,
                                            'char' => 97,
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
                                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                  'line' => 214,
                                                  'char' => 122,
                                                ),
                                                'name' => 'getColumns',
                                                'call-type' => 1,
                                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                'line' => 214,
                                                'char' => 135,
                                              ),
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 214,
                                              'char' => 135,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 214,
                                          'char' => 137,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 214,
                                        'char' => 137,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ')',
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 215,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 215,
                                      'char' => 21,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' REFERENCES `',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 215,
                                      'char' => 37,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 215,
                                    'char' => 37,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'reference',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 215,
                                      'char' => 49,
                                    ),
                                    'name' => 'getReferencedTable',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 215,
                                    'char' => 71,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 215,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '`(',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 215,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 215,
                                'char' => 76,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 215,
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
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 215,
                                        'char' => 108,
                                      ),
                                      'name' => 'getReferencedColumns',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 215,
                                      'char' => 131,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 215,
                                    'char' => 131,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 215,
                                'char' => 133,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 215,
                              'char' => 133,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ')',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 215,
                              'char' => 136,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 215,
                            'char' => 136,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 215,
                          'char' => 136,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 217,
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
                          'variable' => 'onDelete',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 217,
                              'char' => 42,
                            ),
                            'name' => 'getOnDelete',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 217,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 217,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 218,
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
                            'value' => 'onDelete',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 218,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 218,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 218,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 219,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onDelete',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 219,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 219,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 219,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 220,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 222,
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
                          'variable' => 'onUpdate',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 222,
                              'char' => 42,
                            ),
                            'name' => 'getOnUpdate',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 222,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 222,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 223,
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
                            'value' => 'onUpdate',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 223,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 223,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 223,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 224,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onUpdate',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 224,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 224,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 224,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 225,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 227,
                      'char' => 19,
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
                            'value' => 'referenceSql',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 227,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 227,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 228,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 229,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 231,
              'char' => 11,
            ),
            14 => 
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
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 231,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 231,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'createLines',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 231,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 231,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 231,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\\n)',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 231,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 231,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 231,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 233,
              'char' => 14,
            ),
            15 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 233,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 234,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 115,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 115,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 114,
          'last-line' => 238,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 239,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 239,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 239,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 239,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 241,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 243,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 243,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 243,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'sql',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 243,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 243,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 243,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 243,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 243,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 246,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 246,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 246,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 247,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 249,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 249,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 249,
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
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 249,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 249,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 249,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 249,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 249,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 249,
                    'char' => 72,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => ' AS ',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 249,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 249,
                  'char' => 79,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'viewSql',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 249,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 249,
                'char' => 88,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 250,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 240,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 240,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 239,
          'last-line' => 260,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 261,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 261,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 261,
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
                    'value' => 'PRAGMA table_info(\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 263,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 263,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 263,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\')',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 263,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 263,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 264,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 262,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 262,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 261,
          'last-line' => 268,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 269,
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
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'PRAGMA index_info(\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 271,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 271,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 271,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\')',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 271,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 271,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 272,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to query indexes detail on a table
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 270,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 270,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 269,
          'last-line' => 276,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 277,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 277,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 277,
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
                    'value' => 'PRAGMA index_list(\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 279,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 279,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 279,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\')',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 279,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 279,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 280,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 278,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 278,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 277,
          'last-line' => 284,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 285,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 285,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 285,
              'char' => 75,
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
                    'value' => 'PRAGMA foreign_key_list(\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 287,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 287,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 287,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\')',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 287,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 287,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 288,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 286,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 286,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 285,
          'last-line' => 292,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 293,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 293,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 293,
              'char' => 89,
            ),
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
                      'value' => 'Dropping DB column is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 295,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 295,
                    'char' => 74,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 295,
                'char' => 75,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 296,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 294,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 294,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 293,
          'last-line' => 300,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 301,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 301,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 301,
              'char' => 96,
            ),
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
                      'value' => 'Dropping a foreign key constraint is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 305,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 305,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 305,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 306,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 302,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 302,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 301,
          'last-line' => 310,
          'char' => 19,
        ),
        12 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 311,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 311,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 311,
              'char' => 87,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 313,
                'char' => 23,
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
                            'value' => 'DROP INDEX \\"',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 314,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 314,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 314,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\".\\"',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 314,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 314,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'indexName',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 314,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 314,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\\"',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 314,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 314,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 315,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 317,
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
                    'value' => 'DROP INDEX \\"',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 317,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexName',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 317,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 317,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\\"',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 317,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 317,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 318,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 312,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 312,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 311,
          'last-line' => 322,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 323,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 323,
              'char' => 73,
            ),
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
                      'value' => 'Removing a primary key after table has been created is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 327,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 327,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 327,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 328,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 324,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 324,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 323,
          'last-line' => 332,
          'char' => 19,
        ),
        14 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 333,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 333,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 333,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 333,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 333,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 335,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 337,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 337,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 337,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 337,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 337,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 337,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 337,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 337,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 339,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 339,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 340,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'table',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 340,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 340,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 341,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 343,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 343,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 343,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 343,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 344,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 334,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 334,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 333,
          'last-line' => 348,
          'char' => 19,
        ),
        15 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 349,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 349,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 349,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 349,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 349,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 351,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 353,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 353,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 353,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 353,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 353,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 353,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 353,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 353,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 355,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 355,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 356,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'view',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 356,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 356,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 357,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 359,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 359,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'view',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 359,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 359,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 360,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 350,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 350,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 349,
          'last-line' => 365,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'forUpdate',
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 366,
              'char' => 47,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 368,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 369,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a SQL modified with a FOR UPDATE clause. For SQLite it returns
     * the original query
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 367,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 367,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 366,
          'last-line' => 373,
          'char' => 19,
        ),
        17 => 
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 374,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 374,
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
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 376,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'columnSql',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 376,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'typeValues',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 376,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 378,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 378,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 378,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 378,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 378,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 378,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 379,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 379,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 379,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 379,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 379,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 379,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 384,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnType',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 384,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 386,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BIGINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 386,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 386,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 387,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 387,
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
                                'value' => 'BIGINT',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 388,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 388,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 389,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 391,
                      'char' => 18,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 391,
                          'char' => 27,
                        ),
                        'name' => 'isUnsigned',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 391,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => ' UNSIGNED',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 392,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 392,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 393,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 395,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 397,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 397,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 397,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BLOB',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 397,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 397,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 398,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 398,
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
                                'value' => 'BLOB',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 399,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 399,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 400,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 402,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 404,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 404,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 404,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BOOLEAN',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 404,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 404,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 405,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 405,
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
                                'value' => 'TINYINT',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 406,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 406,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 407,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 409,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 411,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 411,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 411,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_CHAR',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 411,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 411,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 412,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 412,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 413,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 413,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 414,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 416,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 416,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 416,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 416,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 416,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 416,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 418,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 420,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 420,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 420,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATE',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 420,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 420,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 421,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 421,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 422,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 422,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 423,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 425,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 427,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 427,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 427,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATETIME',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 427,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 427,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 428,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 428,
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
                                'value' => 'DATETIME',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 429,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 429,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 430,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 432,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 434,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 434,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DECIMAL',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 434,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 434,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 435,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
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
                                'value' => 'NUMERIC',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 436,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 436,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 437,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 439,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 439,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 439,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 439,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 439,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 439,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 441,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 443,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 443,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 443,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DOUBLE',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 443,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 443,
                    'char' => 37,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 444,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 444,
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
                                'value' => 'DOUBLE',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 445,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 445,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 446,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 448,
                      'char' => 18,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 448,
                          'char' => 27,
                        ),
                        'name' => 'isUnsigned',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 448,
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
                              'operator' => 'concat-assign',
                              'variable' => 'columnSql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => ' UNSIGNED',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 449,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 449,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 450,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 452,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 454,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 454,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 454,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_FLOAT',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 454,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 454,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 455,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 455,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 456,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 456,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 457,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 459,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 461,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 461,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 461,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_INTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 461,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 461,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 462,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 462,
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
                                'value' => 'INTEGER',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 463,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 463,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 464,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 466,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 468,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 468,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 468,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_LONGBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 468,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 468,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 469,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 469,
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
                                'value' => 'LONGBLOB',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 470,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 470,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 471,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 473,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 475,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 475,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 475,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_MEDIUMBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 475,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 475,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 476,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 476,
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
                                'value' => 'MEDIUMBLOB',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 477,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 477,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 478,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 480,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 482,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 482,
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
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 482,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TEXT',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 482,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 482,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 483,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 483,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 484,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 484,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 485,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 487,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 489,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 489,
                  'char' => 16,
                ),
                13 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 489,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TIMESTAMP',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 489,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 489,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 490,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 490,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 491,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 491,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 492,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 494,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 496,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 496,
                  'char' => 16,
                ),
                14 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 496,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TINYBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 496,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 496,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 497,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 497,
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
                                'value' => 'TINYBLOB',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 498,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 498,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 499,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 501,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 503,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 503,
                  'char' => 16,
                ),
                15 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 503,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_VARCHAR',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 503,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 503,
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 504,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 504,
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
                                'value' => 'VARCHAR',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 505,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 505,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 506,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 508,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 508,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 508,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 508,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 508,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 508,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 510,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 512,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 512,
                  'char' => 19,
                ),
                16 => 
                array (
                  'type' => 'default',
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
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 513,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 513,
                        'char' => 36,
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
                                    'value' => 'Unrecognized SQLite data type at column ',
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 515,
                                    'char' => 66,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'column',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 515,
                                      'char' => 75,
                                    ),
                                    'name' => 'getName',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 516,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 516,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 516,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 516,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 517,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 519,
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
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 519,
                              'char' => 41,
                            ),
                            'name' => 'getTypeValues',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 519,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 519,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 520,
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
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 520,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 520,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 520,
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
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 521,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 521,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 521,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 521,
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
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 522,
                                  'char' => 34,
                                ),
                                1 => 
                                array (
                                  'variable' => 'valueSql',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 522,
                                  'char' => 44,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 524,
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
                                  'operator' => 'assign',
                                  'variable' => 'valueSql',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 524,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 524,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 526,
                              'char' => 27,
                            ),
                            2 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'typeValues',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 526,
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
                                            'value' => '\\"',
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 527,
                                            'char' => 47,
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
                                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                  'line' => 527,
                                                  'char' => 66,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                'line' => 527,
                                                'char' => 66,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '\\"',
                                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                  'line' => 527,
                                                  'char' => 70,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                                'line' => 527,
                                                'char' => 70,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 527,
                                            'char' => 72,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 527,
                                          'char' => 72,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\", ',
                                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                          'line' => 527,
                                          'char' => 78,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 527,
                                        'char' => 78,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 527,
                                      'char' => 78,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 528,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 530,
                              'char' => 27,
                            ),
                            3 => 
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
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 530,
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
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 530,
                                              'char' => 60,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 530,
                                            'char' => 60,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '0',
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 530,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 530,
                                            'char' => 63,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '-2',
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 530,
                                              'char' => 67,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 530,
                                            'char' => 67,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 530,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 530,
                                      'char' => 69,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 530,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 530,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 530,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 531,
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
                                        'value' => '(\\"',
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 532,
                                        'char' => 45,
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
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 532,
                                              'char' => 69,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 532,
                                            'char' => 69,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '\\"',
                                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                              'line' => 532,
                                              'char' => 73,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                            'line' => 532,
                                            'char' => 73,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                        'line' => 532,
                                        'char' => 75,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 532,
                                      'char' => 75,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\")',
                                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                      'line' => 532,
                                      'char' => 80,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                    'line' => 532,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 532,
                                  'char' => 80,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 533,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 534,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 535,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 535,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 537,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnSql',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 537,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 538,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the column name in SQLite
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 375,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 375,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 374,
          'last-line' => 548,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listIndexesSql',
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 549,
              'char' => 49,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 549,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 549,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'keyName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 549,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 549,
              'char' => 94,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 551,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 553,
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
                        'value' => 'SELECT sql FROM sqlite_master WHERE type = \'index\' AND tbl_name = ',
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 553,
                        'char' => 85,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 553,
                          'char' => 92,
                        ),
                        'name' => 'escape',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'table',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 553,
                              'char' => 105,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 553,
                            'char' => 105,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 553,
                        'char' => 107,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 553,
                      'char' => 107,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' COLLATE NOCASE',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 553,
                      'char' => 123,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 553,
                    'char' => 123,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 553,
                  'char' => 123,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 555,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'keyName',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 555,
                'char' => 20,
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
                            'value' => ' AND name = ',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 556,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 556,
                              'char' => 42,
                            ),
                            'name' => 'escape',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'keyName',
                                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                  'line' => 556,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 556,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 556,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 556,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' COLLATE NOCASE',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 556,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 556,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 556,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 557,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 559,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 559,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 560,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates the SQL to get query list of indexes
     *
     * ```php
     * print_r(
     *     $dialect->listIndexesSql("blog")
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 550,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 550,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 549,
          'last-line' => 570,
          'char' => 19,
        ),
        19 => 
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 571,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 571,
              'char' => 56,
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
                'value' => 'SELECT tbl_name FROM sqlite_master WHERE type = \'table\' ORDER BY tbl_name',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 573,
                'char' => 89,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 574,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 572,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 572,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 571,
          'last-line' => 578,
          'char' => 19,
        ),
        20 => 
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
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 579,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 579,
              'char' => 56,
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
                'value' => 'SELECT tbl_name FROM sqlite_master WHERE type = \'view\' ORDER BY tbl_name',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 581,
                'char' => 88,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 582,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 580,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 580,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 579,
          'last-line' => 586,
          'char' => 19,
        ),
        21 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 587,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 587,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 587,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 587,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 587,
                'char' => 129,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 587,
                'char' => 137,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 587,
              'char' => 137,
            ),
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
                      'value' => 'Altering a DB column is not supported by SQLite',
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 589,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 589,
                    'char' => 76,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 589,
                'char' => 77,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 590,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 588,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 588,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 587,
          'last-line' => 595,
          'char' => 19,
        ),
        22 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 596,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 598,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 599,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 597,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 597,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 596,
          'last-line' => 609,
          'char' => 19,
        ),
        23 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 610,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 610,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 610,
              'char' => 76,
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
                    'value' => 'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type=\'table\' AND tbl_name=\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 612,
                    'char' => 117,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tableName',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 612,
                    'char' => 129,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 612,
                  'char' => 129,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 612,
                  'char' => 132,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 612,
                'char' => 132,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 613,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 611,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 611,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 610,
          'last-line' => 617,
          'char' => 19,
        ),
        24 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 618,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 618,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 618,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 620,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 621,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 619,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 619,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 618,
          'last-line' => 625,
          'char' => 19,
        ),
        25 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 626,
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 626,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 628,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 630,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 630,
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
                                'value' => '\\"',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 631,
                                'char' => 28,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schemaName',
                                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                                'line' => 631,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 631,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\".\\"',
                              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                              'line' => 631,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 631,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 631,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 631,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 631,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 631,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 631,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 632,
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '\\"',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 633,
                            'char' => 28,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                            'line' => 633,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 633,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\\"',
                          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                          'line' => 633,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                        'line' => 633,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                      'line' => 633,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 634,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 636,
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
                  'value' => 'DELETE FROM ',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 636,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 636,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 636,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 637,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 627,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 627,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 626,
          'last-line' => 641,
          'char' => 19,
        ),
        26 => 
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
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 642,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 642,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 642,
              'char' => 74,
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
                    'value' => 'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type=\'view\' AND tbl_name=\'',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 644,
                    'char' => 116,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'viewName',
                    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                    'line' => 644,
                    'char' => 127,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 644,
                  'char' => 127,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                  'line' => 644,
                  'char' => 130,
                ),
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 644,
                'char' => 130,
              ),
              'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
              'line' => 645,
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
                'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
                'line' => 643,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
            'line' => 643,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
          'line' => 642,
          'last-line' => 646,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Dialect/Sqlite.zep',
    'line' => 24,
    'char' => 5,
  ),
);