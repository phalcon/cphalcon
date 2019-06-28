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
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Dialect',
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 17,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 18,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
        'line' => 19,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Generates database specific SQL for the MySQL RDBMS
 *',
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Mysql',
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
            'value' => '`',
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 29,
            'char' => 29,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 34,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                  'variable' => 'afterPosition',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 36,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 36,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 37,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 39,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 39,
                                  'char' => 62,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'schemaName',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 39,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 39,
                                  'char' => 74,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 39,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 39,
                            'char' => 76,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' ADD `',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 39,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 39,
                          'char' => 85,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'column',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 39,
                            'char' => 94,
                          ),
                          'name' => 'getName',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 39,
                          'char' => 105,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 39,
                        'char' => 105,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '` ',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 39,
                        'char' => 110,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 39,
                      'char' => 110,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 39,
                        'char' => 117,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 39,
                            'char' => 144,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 39,
                          'char' => 144,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 39,
                      'char' => 145,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 39,
                    'char' => 145,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 39,
                  'char' => 145,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 41,
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
                  'value' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 41,
                  'char' => 19,
                ),
                'name' => 'hasDefault',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 41,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 42,
                          'char' => 39,
                        ),
                        'name' => 'getDefault',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 42,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 42,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 44,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 44,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 44,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 44,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 44,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'CURRENT_TIMESTAMP',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 44,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 44,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 44,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 45,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 45,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 46,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 47,
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
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 47,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 47,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\"',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 47,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 47,
                                    'char' => 69,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 47,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 47,
                              'char' => 71,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 47,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 47,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 47,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 48,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 49,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 51,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 51,
                  'char' => 19,
                ),
                'name' => 'isNotNull',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 51,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 52,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 52,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 55,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 55,
                  'char' => 19,
                ),
                'name' => 'isAutoIncrement',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 55,
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
                        'value' => ' AUTO_INCREMENT',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 56,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 56,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 57,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 59,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 59,
                  'char' => 19,
                ),
                'name' => 'isFirst',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 59,
                'char' => 30,
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
                        'value' => ' FIRST',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 60,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 60,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 61,
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
                      'variable' => 'afterPosition',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 62,
                          'char' => 40,
                        ),
                        'name' => 'getAfterPosition',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 62,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 62,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 64,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'afterPosition',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 64,
                    'char' => 30,
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
                                'value' => ' AFTER `',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 65,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'afterPosition',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 65,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 65,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '`',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 65,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 65,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 65,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 66,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 69,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 69,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 70,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 34,
          'last-line' => 74,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 75,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 75,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 75,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 75,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 77,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 77,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 78,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 78,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 80,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 80,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 80,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 80,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 80,
                            'char' => 62,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 80,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 80,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 80,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 80,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' ADD',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 80,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 80,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 80,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 81,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 81,
                  'char' => 22,
                ),
                'name' => 'getName',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 81,
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
                            'value' => ' CONSTRAINT `',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 82,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 82,
                              'char' => 49,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 82,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 82,
                          'char' => 60,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '`',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 82,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 82,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 82,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 85,
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
                                'type' => 'string',
                                'value' => ' FOREIGN KEY (',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 85,
                                'char' => 34,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 85,
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
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 85,
                                        'char' => 66,
                                      ),
                                      'name' => 'getColumns',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 85,
                                      'char' => 79,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 85,
                                    'char' => 79,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 85,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 85,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') REFERENCES ',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 85,
                              'char' => 97,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 85,
                            'char' => 97,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 85,
                              'char' => 104,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 85,
                                    'char' => 128,
                                  ),
                                  'name' => 'getReferencedTable',
                                  'call-type' => 1,
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 85,
                                  'char' => 149,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 85,
                                'char' => 149,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'reference',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 85,
                                    'char' => 161,
                                  ),
                                  'name' => 'getReferencedSchema',
                                  'call-type' => 1,
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 85,
                                  'char' => 183,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 85,
                                'char' => 183,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 85,
                            'char' => 185,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 85,
                          'char' => 185,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '(',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 85,
                          'char' => 189,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 85,
                        'char' => 189,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 85,
                          'char' => 196,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 85,
                                'char' => 221,
                              ),
                              'name' => 'getReferencedColumns',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 85,
                              'char' => 244,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 85,
                            'char' => 244,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 85,
                        'char' => 246,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 85,
                      'char' => 246,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 85,
                      'char' => 249,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 85,
                    'char' => 249,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 85,
                  'char' => 249,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 87,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 87,
                      'char' => 34,
                    ),
                    'name' => 'getOnDelete',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 87,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 87,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 88,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 88,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 88,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 88,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 89,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'onDelete',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 89,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 89,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 89,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 92,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 92,
                      'char' => 34,
                    ),
                    'name' => 'getOnUpdate',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 92,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 92,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 93,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 93,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 93,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 93,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 94,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'onUpdate',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 94,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 94,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 94,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 97,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 97,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 98,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 76,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 76,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 75,
          'last-line' => 102,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 103,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 103,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 103,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 103,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 105,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 106,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 106,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 108,
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
                      'type' => 'string',
                      'value' => 'ALTER TABLE ',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 108,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 108,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 108,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 108,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 108,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 108,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 108,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 108,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 108,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 110,
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
                  'variable' => 'indexType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 110,
                      'char' => 31,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 110,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 110,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 112,
              'char' => 10,
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
                    'value' => 'indexType',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 112,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 112,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 112,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => ' ADD ',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 113,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexType',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 113,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 113,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' INDEX ',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 113,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 113,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 113,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 114,
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
                        'type' => 'string',
                        'value' => ' ADD INDEX ',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 115,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 115,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 118,
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
                            'value' => '`',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 118,
                            'char' => 21,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 118,
                              'char' => 29,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 118,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 118,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '` (',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 118,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 118,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 118,
                          'char' => 53,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 118,
                                'char' => 74,
                              ),
                              'name' => 'getColumns',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 118,
                              'char' => 87,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 118,
                            'char' => 87,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 118,
                        'char' => 89,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 118,
                      'char' => 89,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 118,
                      'char' => 92,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 118,
                    'char' => 92,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 118,
                  'char' => 92,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 120,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 120,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 121,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 104,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 104,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 103,
          'last-line' => 125,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 126,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 126,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 126,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 126,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 128,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 128,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 128,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 128,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 128,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 128,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 128,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 128,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' ADD PRIMARY KEY (',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 128,
                      'char' => 94,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 128,
                    'char' => 94,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 128,
                      'char' => 101,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 128,
                            'char' => 122,
                          ),
                          'name' => 'getColumns',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 128,
                          'char' => 135,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 128,
                        'char' => 135,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 128,
                    'char' => 137,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 128,
                  'char' => 137,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => ')',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 128,
                  'char' => 140,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 128,
                'char' => 140,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 129,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 126,
          'last-line' => 133,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 134,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 134,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 134,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 64,
                ),
                6 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 136,
                  'char' => 71,
                ),
                7 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 22,
                ),
                8 => 
                array (
                  'variable' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 34,
                ),
                9 => 
                array (
                  'variable' => 'indexName',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 45,
                ),
                10 => 
                array (
                  'variable' => 'columnLine',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 57,
                ),
                11 => 
                array (
                  'variable' => 'indexType',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 68,
                ),
                12 => 
                array (
                  'variable' => 'onDelete',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 137,
                  'char' => 78,
                ),
                13 => 
                array (
                  'variable' => 'onUpdate',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 138,
                  'char' => 21,
                ),
                14 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 138,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 139,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 139,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 140,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 140,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'referenceSql',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 140,
                  'char' => 38,
                ),
                2 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 140,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 142,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 142,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 142,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 142,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 142,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 142,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 142,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 142,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 145,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 145,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 145,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 148,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 148,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 148,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 148,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 148,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 148,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 148,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 148,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 150,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 150,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 150,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 151,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 151,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 151,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 151,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 151,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 151,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 152,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 152,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'temporary',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 152,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 152,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 152,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 153,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 158,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'temporary',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 158,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 159,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 159,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 159,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' (\\n\\t',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 159,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 159,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 159,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 160,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 161,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 161,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 161,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' (\\n\\t',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 161,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 161,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 161,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 162,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 164,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 164,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 164,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 166,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 166,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 167,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 167,
                                'char' => 41,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 167,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 167,
                            'char' => 52,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '` ',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 167,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 167,
                          'char' => 57,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 167,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 167,
                                'char' => 91,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 167,
                              'char' => 91,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 167,
                          'char' => 92,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 167,
                        'char' => 92,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 167,
                      'char' => 92,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 172,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 172,
                      'char' => 23,
                    ),
                    'name' => 'hasDefault',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 172,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 173,
                              'char' => 43,
                            ),
                            'name' => 'getDefault',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 173,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 173,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 175,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 175,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 175,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 175,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 175,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'CURRENT_TIMESTAMP',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 175,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 175,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 175,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 176,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 176,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 177,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 178,
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
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 178,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 178,
                                        'char' => 76,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\"',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 178,
                                          'char' => 80,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 178,
                                        'char' => 80,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 178,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 178,
                                  'char' => 82,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\"',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 178,
                                  'char' => 86,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 178,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 178,
                              'char' => 86,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 179,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 180,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 185,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 185,
                      'char' => 23,
                    ),
                    'name' => 'isNotNull',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 185,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 186,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 186,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 187,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 192,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 192,
                      'char' => 23,
                    ),
                    'name' => 'isAutoIncrement',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 192,
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
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'columnLine',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' AUTO_INCREMENT',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 193,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 193,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 194,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 199,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 199,
                      'char' => 23,
                    ),
                    'name' => 'isPrimary',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 199,
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
                            'value' => ' PRIMARY KEY',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 200,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 200,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 201,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 203,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 203,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 203,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 204,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 209,
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
                  'value' => 'indexes',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 209,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 209,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'indexes',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 209,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 209,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 209,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 210,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 211,
                              'char' => 39,
                            ),
                            'name' => 'getName',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 211,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 211,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 212,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 212,
                              'char' => 39,
                            ),
                            'name' => 'getType',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 212,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 212,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 217,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'indexName',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 217,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'PRIMARY',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 217,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 217,
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
                                    'value' => 'PRIMARY KEY (',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 218,
                                    'char' => 50,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 218,
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
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 218,
                                            'char' => 78,
                                          ),
                                          'name' => 'getColumns',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 218,
                                          'char' => 91,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 218,
                                        'char' => 91,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 218,
                                    'char' => 93,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 218,
                                  'char' => 93,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ')',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 218,
                                  'char' => 96,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 218,
                                'char' => 96,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 218,
                              'char' => 96,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 219,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 220,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 220,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 220,
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
                                              'type' => 'variable',
                                              'value' => 'indexType',
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 221,
                                              'char' => 50,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ' KEY `',
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 221,
                                              'char' => 59,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 221,
                                            'char' => 59,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'indexName',
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 221,
                                            'char' => 71,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 221,
                                          'char' => 71,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '` (',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 221,
                                          'char' => 77,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 221,
                                        'char' => 77,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 221,
                                          'char' => 84,
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
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 221,
                                                'char' => 105,
                                              ),
                                              'name' => 'getColumns',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 221,
                                              'char' => 118,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 221,
                                            'char' => 118,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 221,
                                        'char' => 120,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 221,
                                      'char' => 120,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 221,
                                      'char' => 123,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 221,
                                    'char' => 123,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 221,
                                  'char' => 123,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 222,
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
                                            'type' => 'string',
                                            'value' => 'KEY `',
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 223,
                                            'char' => 46,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'indexName',
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 223,
                                            'char' => 58,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 223,
                                          'char' => 58,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '` (',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 223,
                                          'char' => 64,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 223,
                                        'char' => 64,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 223,
                                          'char' => 71,
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
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 223,
                                                'char' => 92,
                                              ),
                                              'name' => 'getColumns',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 223,
                                              'char' => 105,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 223,
                                            'char' => 105,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 223,
                                        'char' => 107,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 223,
                                      'char' => 107,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 223,
                                      'char' => 110,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 223,
                                    'char' => 110,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 223,
                                  'char' => 110,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 224,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 225,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 227,
                      'char' => 19,
                    ),
                    3 => 
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 227,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 227,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 228,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 229,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 234,
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
                  'value' => 'references',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 234,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 234,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'references',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 234,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 234,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 234,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 235,
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
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 236,
                                              'char' => 49,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'reference',
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 236,
                                                'char' => 61,
                                              ),
                                              'name' => 'getName',
                                              'call-type' => 1,
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 236,
                                              'char' => 72,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 236,
                                            'char' => 72,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '` FOREIGN KEY (',
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 236,
                                            'char' => 90,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 236,
                                          'char' => 90,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 236,
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
                                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                  'line' => 236,
                                                  'char' => 122,
                                                ),
                                                'name' => 'getColumns',
                                                'call-type' => 1,
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 236,
                                                'char' => 135,
                                              ),
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 236,
                                              'char' => 135,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 236,
                                          'char' => 137,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 236,
                                        'char' => 137,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ')',
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 237,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 237,
                                      'char' => 21,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' REFERENCES `',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 237,
                                      'char' => 37,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 237,
                                    'char' => 37,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'reference',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 237,
                                      'char' => 49,
                                    ),
                                    'name' => 'getReferencedTable',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 237,
                                    'char' => 71,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 237,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '`(',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 237,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 237,
                                'char' => 76,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 237,
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
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 237,
                                        'char' => 108,
                                      ),
                                      'name' => 'getReferencedColumns',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 237,
                                      'char' => 131,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 237,
                                    'char' => 131,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 237,
                                'char' => 133,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 237,
                              'char' => 133,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ')',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 237,
                              'char' => 136,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 237,
                            'char' => 136,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 237,
                          'char' => 136,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 239,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 239,
                              'char' => 42,
                            ),
                            'name' => 'getOnDelete',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 239,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 239,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 240,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 240,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 240,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 240,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 241,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onDelete',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 241,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 241,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 241,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 242,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 244,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 244,
                              'char' => 42,
                            ),
                            'name' => 'getOnUpdate',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 244,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 244,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 245,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 245,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 245,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 245,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 246,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onUpdate',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 246,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 246,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 246,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 247,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 249,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 249,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 249,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 250,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 251,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 253,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 253,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 253,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'createLines',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 253,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 253,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 253,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\\n)',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 253,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 253,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 253,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 255,
              'char' => 10,
            ),
            13 => 
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 255,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 255,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 255,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 255,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 256,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 256,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 256,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 256,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 256,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 256,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 256,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 257,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 259,
              'char' => 14,
            ),
            14 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 259,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 260,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 134,
          'last-line' => 264,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 265,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 265,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 265,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 265,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 267,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 269,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 269,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 269,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'sql',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 269,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 269,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 269,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 269,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 269,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 272,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 272,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 272,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 273,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 275,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 275,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 275,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 275,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 275,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 275,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 275,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 275,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 275,
                    'char' => 72,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => ' AS ',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 275,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 275,
                  'char' => 79,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'viewSql',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 275,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 275,
                'char' => 88,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 276,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 266,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 266,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 265,
          'last-line' => 286,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 287,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 287,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 287,
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
                  'type' => 'string',
                  'value' => 'DESCRIBE ',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 289,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 289,
                    'char' => 33,
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
                        'value' => 'table',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 289,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 289,
                      'char' => 52,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 289,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 289,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 289,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 289,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 290,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 288,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 288,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 287,
          'last-line' => 294,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 295,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 295,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 295,
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
                  'type' => 'string',
                  'value' => 'SHOW INDEXES FROM ',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 297,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 297,
                    'char' => 42,
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
                        'value' => 'table',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 297,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 297,
                      'char' => 61,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 297,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 297,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 297,
                  'char' => 70,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 297,
                'char' => 70,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 298,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 296,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 296,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 295,
          'last-line' => 302,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 303,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 303,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 303,
              'char' => 75,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 305,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 307,
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
                    'type' => 'string',
                    'value' => 'SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 307,
                    'char' => 452,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 307,
                  'char' => 452,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 309,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schema',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 309,
                'char' => 19,
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
                                'value' => 'KCU.CONSTRAINT_SCHEMA = \'',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 310,
                                'char' => 49,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 310,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 310,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\' AND KCU.TABLE_NAME = \'',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 310,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 310,
                            'char' => 85,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 310,
                            'char' => 93,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 310,
                          'char' => 93,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\'',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 310,
                          'char' => 96,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 310,
                        'char' => 96,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 310,
                      'char' => 96,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 311,
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
                            'value' => 'KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = \'',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 312,
                            'char' => 81,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 312,
                            'char' => 89,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 312,
                          'char' => 89,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\'',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 312,
                          'char' => 92,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 312,
                        'char' => 92,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 312,
                      'char' => 92,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 313,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 315,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 315,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 316,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 304,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 304,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 303,
          'last-line' => 320,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 321,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 321,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 321,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 323,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 323,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 323,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 323,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 323,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 323,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 323,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 323,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP COLUMN `',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 323,
                      'char' => 90,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 323,
                    'char' => 90,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columnName',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 323,
                    'char' => 103,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 323,
                  'char' => 103,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '`',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 323,
                  'char' => 106,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 323,
                'char' => 106,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 324,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 322,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 322,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 321,
          'last-line' => 328,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 329,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 329,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 329,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 331,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 331,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 331,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 331,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 331,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 331,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 331,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 331,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP FOREIGN KEY `',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 331,
                      'char' => 95,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 331,
                    'char' => 95,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referenceName',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 331,
                    'char' => 111,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 331,
                  'char' => 111,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '`',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 331,
                  'char' => 114,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 331,
                'char' => 114,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 332,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 330,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 330,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 329,
          'last-line' => 336,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 337,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 337,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 337,
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
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'ALTER TABLE ',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 339,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 339,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 339,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 339,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'schemaName',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 339,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 339,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 339,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 339,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ' DROP INDEX `',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 339,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 339,
                    'char' => 89,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'indexName',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 339,
                    'char' => 101,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 339,
                  'char' => 101,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '`',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 339,
                  'char' => 104,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 339,
                'char' => 104,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 340,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 338,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 338,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 337,
          'last-line' => 344,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 345,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 345,
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
                    'type' => 'string',
                    'value' => 'ALTER TABLE ',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 347,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 347,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 347,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 347,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 347,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 347,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 347,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 347,
                  'char' => 73,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => ' DROP PRIMARY KEY',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 347,
                  'char' => 92,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 347,
                'char' => 92,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 348,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 346,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 346,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 345,
          'last-line' => 352,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 353,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 353,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 353,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 353,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 353,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 355,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 357,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 357,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 357,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 357,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 357,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 357,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 357,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 357,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 359,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 359,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 360,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'table',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 360,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 360,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 361,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 363,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 363,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 363,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 363,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 364,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 354,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 354,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 353,
          'last-line' => 368,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 369,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 369,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 369,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 369,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 369,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 371,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 373,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 373,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 373,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 373,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 373,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 373,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 373,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 373,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 375,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ifExists',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 375,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 376,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'view',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 376,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 376,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 377,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 379,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 379,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'view',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 379,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 379,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 380,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 369,
          'last-line' => 384,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 385,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 385,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 387,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'columnSql',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 387,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'typeValues',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 387,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 389,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 389,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 389,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 389,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 389,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 389,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 390,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 390,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 390,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 390,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 390,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 390,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 392,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnType',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 392,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 394,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BIGINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 394,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 394,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 395,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 395,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 396,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 396,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 397,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 399,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 399,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 399,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 399,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 399,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 399,
                                'char' => 68,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 399,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 399,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 399,
                              'char' => 96,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 399,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 399,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 401,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 403,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 403,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 403,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BIT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 403,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 403,
                    'char' => 34,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 404,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                'value' => 'BIT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 405,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 405,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 406,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 408,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 408,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 408,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 408,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 410,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 412,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 412,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 412,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BLOB',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 412,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 413,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                'value' => 'BLOB',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 414,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 414,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 415,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 417,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 419,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 419,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 419,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_BOOLEAN',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 419,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 419,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 420,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
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
                                'value' => 'TINYINT(1)',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 421,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 421,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 422,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 424,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 426,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 426,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 426,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_CHAR',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 426,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 426,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 427,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 427,
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
                                'value' => 'CHAR',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 428,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 428,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 429,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 431,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 431,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 431,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 431,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 431,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 431,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 433,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 435,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 435,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 435,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATE',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 435,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 435,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 436,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 436,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 437,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 437,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 438,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 440,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 442,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 442,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 442,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DATETIME',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 442,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 442,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 443,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 443,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 444,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 444,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 445,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 447,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 449,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 449,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 449,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DECIMAL',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 449,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 449,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 450,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 450,
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
                                'value' => 'DECIMAL',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 451,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 451,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 452,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 454,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 454,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 454,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 454,
                                  'char' => 67,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 454,
                              'char' => 69,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 454,
                                'char' => 76,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 454,
                                    'char' => 103,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 454,
                                  'char' => 103,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 454,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 454,
                            'char' => 104,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 454,
                          'char' => 104,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 456,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 458,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 458,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 458,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_DOUBLE',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 458,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 458,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 459,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 459,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 460,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 460,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 461,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 463,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 463,
                                'char' => 38,
                              ),
                              'name' => 'checkColumnSizeAndScale',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 463,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 463,
                                  'char' => 69,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 463,
                              'char' => 71,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 463,
                                'char' => 78,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 463,
                                    'char' => 105,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 463,
                                  'char' => 105,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 463,
                              'char' => 106,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 463,
                            'char' => 106,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 463,
                          'char' => 106,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 465,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 467,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 467,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 467,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_ENUM',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 467,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 467,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 468,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 468,
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
                                'value' => 'ENUM',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 469,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 469,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 470,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 472,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 472,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 472,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 472,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 472,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 472,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 474,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 476,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 476,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 476,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_FLOAT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 476,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 476,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 477,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 477,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 478,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 478,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 479,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 481,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 481,
                                'char' => 38,
                              ),
                              'name' => 'checkColumnSizeAndScale',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 481,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 481,
                                  'char' => 69,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 481,
                              'char' => 71,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 481,
                                'char' => 78,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 481,
                                    'char' => 105,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 481,
                                  'char' => 105,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 481,
                              'char' => 106,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 481,
                            'char' => 106,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 481,
                          'char' => 106,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 483,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 485,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 485,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 485,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_INTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 485,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 485,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 486,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 486,
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
                                'value' => 'INT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 487,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 487,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 488,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 490,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 490,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 490,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 490,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 490,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 490,
                                'char' => 68,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 490,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 490,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 490,
                              'char' => 96,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 490,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 490,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 492,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 494,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 494,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 494,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_JSON',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 494,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 494,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 495,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 495,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 496,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 496,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 497,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 499,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 501,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 501,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 501,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_LONGBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 501,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 501,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 502,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 502,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 503,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 503,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 504,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 506,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 508,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 508,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 508,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_LONGTEXT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 508,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 508,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 509,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 509,
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
                                'value' => 'LONGTEXT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 510,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 510,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 511,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 513,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 515,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 515,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 515,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_MEDIUMBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 515,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 515,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 516,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 516,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 517,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 517,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 518,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 520,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 522,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 522,
                  'char' => 16,
                ),
                16 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 522,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_MEDIUMINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 522,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 522,
                    'char' => 44,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 523,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 523,
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
                                'value' => 'MEDIUMINT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 524,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 524,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 525,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 527,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 527,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 527,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 527,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 527,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 527,
                                'char' => 68,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 527,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 527,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 527,
                              'char' => 96,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 527,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 527,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 529,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 531,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 531,
                  'char' => 16,
                ),
                17 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 531,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_MEDIUMTEXT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 531,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 531,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 532,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 532,
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
                                'value' => 'MEDIUMTEXT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 533,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 533,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 534,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 536,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 538,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 538,
                  'char' => 16,
                ),
                18 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 538,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_SMALLINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 538,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 538,
                    'char' => 43,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 539,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 539,
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
                                'value' => 'SMALLINT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 540,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 540,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 541,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 543,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 543,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 543,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 543,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 543,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 543,
                                'char' => 68,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 543,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 543,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 543,
                              'char' => 96,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 543,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 543,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 545,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 547,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 547,
                  'char' => 16,
                ),
                19 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 547,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TEXT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 547,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 547,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 548,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 548,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 549,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 549,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 550,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 552,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 554,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 554,
                  'char' => 16,
                ),
                20 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 554,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TIME',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 554,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 554,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 555,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 555,
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
                                'value' => 'TIME',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 556,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 556,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 557,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 559,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 561,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 561,
                  'char' => 16,
                ),
                21 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 561,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TIMESTAMP',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 561,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 561,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 562,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 562,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 563,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 563,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 564,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 566,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 568,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 568,
                  'char' => 16,
                ),
                22 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 568,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TINYBLOB',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 568,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 568,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 569,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 569,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 570,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 570,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 571,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 573,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 575,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 575,
                  'char' => 16,
                ),
                23 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 575,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TINYINTEGER',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 575,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 575,
                    'char' => 42,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 576,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 576,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 577,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 577,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 578,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 580,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 580,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 580,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 580,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 580,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 580,
                                'char' => 68,
                              ),
                              'name' => 'checkColumnUnsigned',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 580,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 580,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 580,
                              'char' => 96,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 580,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 580,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 582,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 584,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 584,
                  'char' => 16,
                ),
                24 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 584,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_TINYTEXT',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 584,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 584,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 585,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 585,
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
                                'value' => 'TINYTEXT',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 586,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 586,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 587,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 589,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 591,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 591,
                  'char' => 16,
                ),
                25 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Column',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 591,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'TYPE_VARCHAR',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 591,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 591,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 592,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 592,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 593,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 593,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 594,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 596,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 596,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 596,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 596,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 596,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 596,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 598,
                      'char' => 21,
                    ),
                    2 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 600,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 600,
                  'char' => 19,
                ),
                26 => 
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 601,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 601,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 601,
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
                                    'value' => 'Unrecognized MySQL data type at column ',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 603,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'column',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 603,
                                      'char' => 74,
                                    ),
                                    'name' => 'getName',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 604,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 604,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 604,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 604,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 605,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 607,
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
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 607,
                              'char' => 41,
                            ),
                            'name' => 'getTypeValues',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 607,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 607,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 608,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 608,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 608,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 608,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 609,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 609,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 609,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 609,
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
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 610,
                                  'char' => 34,
                                ),
                                1 => 
                                array (
                                  'variable' => 'valueSql',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 610,
                                  'char' => 44,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 612,
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
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 612,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 612,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 614,
                              'char' => 27,
                            ),
                            2 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'typeValues',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 614,
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
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 615,
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
                                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                  'line' => 615,
                                                  'char' => 66,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 615,
                                                'char' => 66,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '\\"',
                                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                  'line' => 615,
                                                  'char' => 70,
                                                ),
                                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                                'line' => 615,
                                                'char' => 70,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 615,
                                            'char' => 72,
                                          ),
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 615,
                                          'char' => 72,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\", ',
                                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                          'line' => 615,
                                          'char' => 78,
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 615,
                                        'char' => 78,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 615,
                                      'char' => 78,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 616,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 618,
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
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 618,
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
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 618,
                                              'char' => 60,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 618,
                                            'char' => 60,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '0',
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 618,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 618,
                                            'char' => 63,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '-2',
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 618,
                                              'char' => 67,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 618,
                                            'char' => 67,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 618,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 618,
                                      'char' => 69,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ')',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 618,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 618,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 618,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 619,
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
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 620,
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
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 620,
                                              'char' => 69,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 620,
                                            'char' => 69,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '\\"',
                                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                              'line' => 620,
                                              'char' => 73,
                                            ),
                                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                            'line' => 620,
                                            'char' => 73,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                        'line' => 620,
                                        'char' => 75,
                                      ),
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 620,
                                      'char' => 75,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\")',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 620,
                                      'char' => 80,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 620,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 620,
                                  'char' => 80,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 621,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 622,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 623,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 623,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 625,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnSql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 625,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 626,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the column name in MySQL
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 386,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 386,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 385,
          'last-line' => 630,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getForeignKeyChecks',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => 'SELECT @@foreign_key_checks',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 633,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 634,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 632,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 632,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 631,
          'last-line' => 644,
          'char' => 19,
        ),
        17 => 
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 645,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 645,
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
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 647,
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
                        'type' => 'string',
                        'value' => 'SHOW TABLES FROM `',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 648,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemaName',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 648,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 648,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '`',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 648,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 648,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 649,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 651,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => 'SHOW TABLES',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 651,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 652,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 646,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 646,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 645,
          'last-line' => 656,
          'char' => 19,
        ),
        18 => 
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 657,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 657,
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
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 659,
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
                        'type' => 'string',
                        'value' => 'SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = \'',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 660,
                        'char' => 112,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemaName',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 660,
                        'char' => 125,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 660,
                      'char' => 125,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\' ORDER BY view_name',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 660,
                      'char' => 147,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 660,
                    'char' => 147,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 661,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 663,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => 'SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 663,
                'char' => 135,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 664,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 658,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 658,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 657,
          'last-line' => 668,
          'char' => 19,
        ),
        19 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 669,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 669,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 669,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 669,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 669,
                'char' => 129,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 669,
                'char' => 137,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 669,
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
                  'variable' => 'afterPosition',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 671,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 671,
                  'char' => 40,
                ),
                2 => 
                array (
                  'variable' => 'columnDefinition',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 671,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 672,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 672,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 674,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 674,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 674,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 674,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 674,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 674,
                  'char' => 65,
                ),
                1 => 
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
                      'value' => 'ALTER TABLE ',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 675,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 675,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 675,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 675,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 675,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 675,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 675,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 675,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 675,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 677,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 677,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 677,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 677,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 677,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 678,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 678,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 679,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 681,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 681,
                    'char' => 19,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 681,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'currentColumn',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 681,
                    'char' => 48,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 681,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 681,
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
                                  'type' => 'string',
                                  'value' => ' CHANGE COLUMN `',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 682,
                                  'char' => 40,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'currentColumn',
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 682,
                                    'char' => 56,
                                  ),
                                  'name' => 'getName',
                                  'call-type' => 1,
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 682,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 682,
                                'char' => 67,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '` `',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 682,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 682,
                              'char' => 73,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 682,
                                'char' => 82,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 682,
                              'char' => 93,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 682,
                            'char' => 93,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '` ',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 682,
                            'char' => 98,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 682,
                          'char' => 98,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnDefinition',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 682,
                          'char' => 116,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 682,
                        'char' => 116,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 682,
                      'char' => 116,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 683,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' MODIFY `',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 684,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'column',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 684,
                                'char' => 42,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 684,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 684,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '` ',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 684,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 684,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnDefinition',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 684,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 684,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 684,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 685,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 687,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 687,
                  'char' => 19,
                ),
                'name' => 'hasDefault',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 687,
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
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 688,
                          'char' => 39,
                        ),
                        'name' => 'getDefault',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 688,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 688,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 690,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 690,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 690,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 690,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 690,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'CURRENT_TIMESTAMP',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 690,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 690,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 690,
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
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 691,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 691,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 692,
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
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 693,
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
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 693,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 693,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\"',
                                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                      'line' => 693,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                    'line' => 693,
                                    'char' => 69,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 693,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 693,
                              'char' => 71,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 693,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 693,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 693,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 694,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 695,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 697,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 697,
                  'char' => 19,
                ),
                'name' => 'isNotNull',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 697,
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
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 698,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 698,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 699,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 701,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 701,
                  'char' => 19,
                ),
                'name' => 'isAutoIncrement',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 701,
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
                        'value' => ' AUTO_INCREMENT',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 702,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 702,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 703,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 705,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'column',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 705,
                  'char' => 19,
                ),
                'name' => 'isFirst',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 705,
                'char' => 30,
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
                        'value' => ' FIRST',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 706,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 706,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 707,
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
                      'variable' => 'afterPosition',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 708,
                          'char' => 40,
                        ),
                        'name' => 'getAfterPosition',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 708,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 708,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 710,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'afterPosition',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 710,
                    'char' => 30,
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
                                'value' => ' AFTER `',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 711,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'afterPosition',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 711,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 711,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '`',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 711,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 711,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 711,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 712,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 713,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 715,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 715,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 716,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 670,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 670,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 669,
          'last-line' => 726,
          'char' => 19,
        ),
        20 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 727,
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
                  'type' => 'variable',
                  'value' => 'sqlQuery',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 729,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => ' LOCK IN SHARE MODE',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 729,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 729,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 730,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a SQL modified with a LOCK IN SHARE MODE clause
     *
     *```php
     * $sql = $dialect->sharedLock("SELECT * FROM robots");
     *
     * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
     *```
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 728,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 728,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 727,
          'last-line' => 740,
          'char' => 19,
        ),
        21 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 741,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 741,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 741,
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
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 743,
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
                            'value' => 'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= \'',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 744,
                            'char' => 107,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 744,
                            'char' => 119,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 744,
                          'char' => 119,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\' AND `TABLE_SCHEMA` = \'',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 744,
                          'char' => 146,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 744,
                        'char' => 146,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemaName',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 744,
                        'char' => 159,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 744,
                      'char' => 159,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\'',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 744,
                      'char' => 162,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 744,
                    'char' => 162,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 745,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 747,
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
                    'value' => 'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = \'',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 747,
                    'char' => 104,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tableName',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 747,
                    'char' => 116,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 747,
                  'char' => 116,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' AND `TABLE_SCHEMA` = DATABASE()',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 747,
                  'char' => 151,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 747,
                'char' => 151,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 748,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 742,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 742,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 741,
          'last-line' => 752,
          'char' => 19,
        ),
        22 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 753,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 753,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 753,
              'char' => 69,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 755,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 757,
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
                    'type' => 'string',
                    'value' => 'SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 757,
                    'char' => 201,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 757,
                  'char' => 201,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 759,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schema',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 759,
                'char' => 19,
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
                              'type' => 'variable',
                              'value' => 'sql',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 760,
                              'char' => 24,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'TABLES.TABLE_SCHEMA = \'',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 760,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 760,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 760,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 760,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\' AND TABLES.TABLE_NAME = \'',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 760,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 760,
                        'char' => 89,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'table',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 760,
                        'char' => 97,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 760,
                      'char' => 97,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\'',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 760,
                      'char' => 100,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 760,
                    'char' => 100,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 761,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 763,
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
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sql',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 763,
                      'char' => 20,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = \'',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 763,
                      'char' => 81,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 763,
                    'char' => 81,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'table',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 763,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 763,
                  'char' => 89,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\'',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 763,
                  'char' => 92,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 763,
                'char' => 92,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 764,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 754,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 754,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 753,
          'last-line' => 768,
          'char' => 19,
        ),
        23 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 769,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 769,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 771,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 773,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 773,
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
                                'value' => '`',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 774,
                                'char' => 27,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schemaName',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 774,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 774,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '`.`',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 774,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 774,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 774,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 774,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '`',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 774,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 774,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 774,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 775,
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
                            'value' => '`',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 776,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 776,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 776,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '`',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 776,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 776,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 776,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 777,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 779,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 779,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'table',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 779,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 779,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 780,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 770,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 770,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 769,
          'last-line' => 784,
          'char' => 19,
        ),
        24 => 
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 785,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 785,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 785,
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
                'type' => 'variable',
                'value' => 'schemaName',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 787,
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
                            'value' => 'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= \'',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 788,
                            'char' => 106,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'viewName',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 788,
                            'char' => 117,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 788,
                          'char' => 117,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\' AND `TABLE_SCHEMA`=\'',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 788,
                          'char' => 142,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 788,
                        'char' => 142,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemaName',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 788,
                        'char' => 155,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 788,
                      'char' => 155,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '\'',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 788,
                      'char' => 158,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 788,
                    'char' => 158,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 789,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 791,
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
                    'value' => 'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`=\'',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 791,
                    'char' => 101,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'viewName',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 791,
                    'char' => 112,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 791,
                  'char' => 112,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '\' AND `TABLE_SCHEMA` = DATABASE()',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 791,
                  'char' => 147,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 791,
                'char' => 147,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 792,
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 786,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 786,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 785,
          'last-line' => 796,
          'char' => 19,
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
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 797,
              'char' => 57,
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
                  'variable' => 'options',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 799,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'engine',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 799,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 799,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'tableCollation',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 799,
                  'char' => 59,
                ),
                4 => 
                array (
                  'variable' => 'collationParts',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 799,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 800,
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
                  'variable' => 'tableOptions',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 800,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 802,
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 802,
                    'char' => 48,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 802,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'options',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 802,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 802,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 802,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 802,
                'char' => 48,
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
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 803,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 804,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 806,
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
                  'variable' => 'tableOptions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 806,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 806,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 811,
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
                  'value' => 'engine',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 811,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 811,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'ENGINE',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 811,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 811,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 811,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'engine',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 812,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'tableOptions',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'ENGINE=',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 813,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'engine',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 813,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 813,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 813,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 814,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 815,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 820,
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
                  'value' => 'autoIncrement',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 820,
                  'char' => 57,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 820,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'AUTO_INCREMENT',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 820,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 820,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 820,
                'char' => 57,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'autoIncrement',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 821,
                    'char' => 30,
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
                          'variable' => 'tableOptions',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'AUTO_INCREMENT=',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 822,
                              'char' => 54,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'autoIncrement',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 822,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 822,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 822,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 823,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 824,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 829,
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
                  'value' => 'tableCollation',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 829,
                  'char' => 59,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 829,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'TABLE_COLLATION',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 829,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 829,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 829,
                'char' => 59,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tableCollation',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 830,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'collationParts',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'explode',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '_',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 831,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 831,
                                'char' => 47,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'tableCollation',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 831,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 831,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 831,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 831,
                          'char' => 64,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'tableOptions',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'DEFAULT CHARSET=',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 832,
                              'char' => 55,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'collationParts',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 832,
                                'char' => 71,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 832,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 832,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 832,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 832,
                          'char' => 74,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'tableOptions',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'COLLATE=',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 833,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tableCollation',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 833,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 833,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 833,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 834,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 835,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 837,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'value' => ' ',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 837,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 837,
                    'char' => 22,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tableOptions',
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 837,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 837,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 837,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 838,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates SQL to add the table creation options
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 798,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 798,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 797,
          'last-line' => 843,
          'char' => 22,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkColumnSizeAndScale',
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 844,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 844,
              'char' => 70,
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
                  'variable' => 'columnSql',
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 846,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 848,
              'char' => 10,
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 848,
                  'char' => 19,
                ),
                'name' => 'getSize',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 848,
                'char' => 30,
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '(',
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 849,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'column',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 849,
                            'char' => 40,
                          ),
                          'name' => 'getSize',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 849,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 849,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 849,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 851,
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
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 851,
                      'char' => 23,
                    ),
                    'name' => 'getScale',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 851,
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
                                'value' => ',',
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 852,
                                'char' => 35,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'column',
                                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                  'line' => 852,
                                  'char' => 44,
                                ),
                                'name' => 'getScale',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                                'line' => 852,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 852,
                              'char' => 56,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ')',
                              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                              'line' => 852,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 852,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 852,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 853,
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
                          'variable' => 'columnSql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ')',
                            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                            'line' => 854,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                          'line' => 854,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 855,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 856,
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
                      'variable' => 'columnSql',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ')',
                        'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                        'line' => 857,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                      'line' => 857,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 858,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 860,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columnSql',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 860,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 861,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if the size and/or scale are present and encloses those values
     * in parentheses if need be
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 845,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 845,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 844,
          'last-line' => 865,
          'char' => 20,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkColumnUnsigned',
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 866,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 866,
              'char' => 66,
            ),
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
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 868,
                  'char' => 19,
                ),
                'name' => 'isUnsigned',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 868,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => ' UNSIGNED',
                    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                    'line' => 869,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                  'line' => 870,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 872,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 872,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
              'line' => 873,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a column is unsigned or not and returns the relevant SQL syntax
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
                'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
                'line' => 867,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
            'line' => 867,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
          'line' => 866,
          'last-line' => 874,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Dialect/Mysql.zep',
    'line' => 24,
    'char' => 5,
  ),
);