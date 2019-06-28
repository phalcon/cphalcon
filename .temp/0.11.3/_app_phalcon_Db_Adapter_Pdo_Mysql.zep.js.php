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
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Adapter\\Pdo',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\Adapter\\Pdo',
        'alias' => 'PdoAdapter',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 14,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\Column',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 15,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\ColumnInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\Exception',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 17,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\Index',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 18,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
        'name' => 'Phalcon\\Db\\IndexInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 19,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\Reference',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 20,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\ReferenceInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
        'line' => 21,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 39,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Specific functions for the Mysql database system
 *
 *```php
 * use Phalcon\\Db\\Adapter\\Pdo\\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *```
 *',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 40,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'Mysql',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'PdoAdapter',
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
          'name' => 'dialectType',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'mysql',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 45,
            'char' => 34,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 49,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'mysql',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 50,
            'char' => 27,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 54,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 55,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 55,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 55,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 55,
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
                  'variable' => 'foreignKeyCheck',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 57,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 59,
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
                  'variable' => 'foreignKeyCheck',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 59,
                      'char' => 36,
                    ),
                    'name' => 'prepare',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 60,
                              'char' => 18,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'dialect',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 60,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 60,
                            'char' => 27,
                          ),
                          'name' => 'getForeignKeyChecks',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 61,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 61,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 61,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 61,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 63,
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'foreignKeyCheck',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 63,
                      'char' => 38,
                    ),
                    'name' => 'execute',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 63,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 63,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 63,
                'char' => 49,
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
                          'value' => 'DATABASE PARAMETER \'FOREIGN_KEY_CHECKS\' HAS TO BE 1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 66,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 66,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 66,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 69,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 69,
                  'char' => 21,
                ),
                'name' => 'execute',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 70,
                          'char' => 18,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 70,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 70,
                        'char' => 27,
                      ),
                      'name' => 'addForeignKey',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tableName',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 71,
                            'char' => 26,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 71,
                          'char' => 26,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schemaName',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 72,
                            'char' => 27,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 72,
                          'char' => 27,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'reference',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 74,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 74,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 75,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 75,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 75,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 76,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a foreign key to a table
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 56,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 55,
          'last-line' => 86,
          'char' => 19,
        ),
        1 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 87,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 87,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 87,
              'char' => 71,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'columnType',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'fields',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'oldColumn',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 58,
                ),
                5 => 
                array (
                  'variable' => 'sizePattern',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 71,
                ),
                6 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 89,
                  'char' => 80,
                ),
                7 => 
                array (
                  'variable' => 'matchOne',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 90,
                  'char' => 21,
                ),
                8 => 
                array (
                  'variable' => 'matchTwo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 90,
                  'char' => 31,
                ),
                9 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 90,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 91,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 91,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 93,
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
                  'variable' => 'oldColumn',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 93,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 93,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'sizePattern',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '#\\\\(([0-9]+)(?:,\\\\s*([0-9]+))*\\\\)#',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 94,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 94,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 96,
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
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 96,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 96,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 98,
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
                  'variable' => 'fields',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 98,
                      'char' => 27,
                    ),
                    'name' => 'fetchAll',
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
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 99,
                              'char' => 18,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'dialect',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 99,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 99,
                            'char' => 27,
                          ),
                          'name' => 'describeColumns',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'table',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 99,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 99,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 99,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 99,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 99,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 99,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Db',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 101,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'FETCH_NUM',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 101,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 101,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 101,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 101,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 101,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 109,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'fields',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 109,
                'char' => 29,
              ),
              'value' => 'field',
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
                      'variable' => 'definition',
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'bindType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 114,
                              'char' => 25,
                            ),
                            'value' => 
                            array (
                              'type' => 'static-constant-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Column',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 115,
                                'char' => 13,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'BIND_PARAM_STR',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 115,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 115,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 115,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 115,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 115,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 121,
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
                      'variable' => 'columnType',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 121,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 121,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 121,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 121,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 135,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 135,
                    'char' => 25,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 139,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 139,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyint(1)',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 139,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 139,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 139,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 143,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 143,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BOOLEAN',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 143,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 143,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 143,
                              'char' => 64,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 144,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 144,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 144,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 145,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 145,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BOOL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 145,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 145,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 145,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 147,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 152,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 152,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 152,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 152,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'bigint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 152,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 152,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 152,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 153,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 153,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIGINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 153,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 153,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 153,
                              'char' => 67,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 154,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 154,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 154,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 155,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 155,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 155,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 155,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 155,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 157,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 162,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 162,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 162,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 162,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 162,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 162,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 162,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 163,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 163,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 163,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 163,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 163,
                              'char' => 70,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 164,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 164,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 164,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 165,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 165,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 165,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 165,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 165,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 167,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 172,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 172,
                      'char' => 20,
                    ),
                    3 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 172,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 172,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'smallint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 172,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 172,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 172,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 173,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 173,
                                  'char' => 69,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_SMALLINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 173,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 173,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 173,
                              'char' => 69,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 174,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 174,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 174,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 175,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 175,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 175,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 175,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 175,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 177,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 182,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 182,
                      'char' => 20,
                    ),
                    4 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 182,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 182,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 182,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 182,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 182,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 186,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 186,
                                  'char' => 68,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 186,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 186,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 186,
                              'char' => 68,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 187,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 187,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 187,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 188,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 188,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 188,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 188,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 188,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 190,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 195,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 195,
                      'char' => 20,
                    ),
                    5 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 195,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 195,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'int',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 195,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 195,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 195,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 196,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 196,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_INTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 196,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 196,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 196,
                              'char' => 64,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 197,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 197,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 197,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 198,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 198,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 198,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 198,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 198,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 200,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 205,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 205,
                      'char' => 20,
                    ),
                    6 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 205,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 205,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'bit',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 205,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 205,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 205,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 206,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 206,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 206,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 206,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 206,
                              'char' => 60,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 207,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 207,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 207,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 207,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 207,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 209,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 214,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 214,
                      'char' => 20,
                    ),
                    7 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 214,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 214,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'enum',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 214,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 214,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 214,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 215,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 215,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_ENUM',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 215,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 215,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 215,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 217,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 222,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 222,
                      'char' => 20,
                    ),
                    8 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 222,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 222,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'datetime',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 222,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 222,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 222,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 223,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 223,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATETIME',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 223,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 223,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 223,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 225,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 230,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 230,
                      'char' => 20,
                    ),
                    9 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 230,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 230,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'date',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 230,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 230,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 230,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 231,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 231,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATE',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 231,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 231,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 231,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 233,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 239,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 239,
                      'char' => 20,
                    ),
                    10 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 239,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 239,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'decimal',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 239,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 239,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 239,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 240,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 240,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 240,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 240,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 240,
                              'char' => 64,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 241,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 241,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 241,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 243,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 248,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 248,
                      'char' => 20,
                    ),
                    11 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 248,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 248,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'double',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 248,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 248,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 248,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 249,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 249,
                                  'char' => 63,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DOUBLE',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 249,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 249,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 249,
                              'char' => 63,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 250,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 250,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 250,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 251,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 251,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 251,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 251,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 251,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 253,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 258,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 258,
                      'char' => 20,
                    ),
                    12 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 258,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 258,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'float',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 258,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 258,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 258,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 259,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 259,
                                  'char' => 62,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_FLOAT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 259,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 259,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 259,
                              'char' => 62,
                            ),
                            1 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 260,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 260,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 260,
                              'char' => 53,
                            ),
                            2 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 261,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 261,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 261,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 261,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 261,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 263,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 268,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 268,
                      'char' => 20,
                    ),
                    13 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 268,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 268,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 268,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 268,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 268,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 269,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 269,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMBLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 269,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 269,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 269,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 271,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 276,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 276,
                      'char' => 20,
                    ),
                    14 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 276,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 276,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'longblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 276,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 276,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 276,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 277,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 277,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGBLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 277,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 277,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 277,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 279,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 284,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 284,
                      'char' => 20,
                    ),
                    15 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 284,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 284,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 284,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 284,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 284,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 285,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 285,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYBLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 285,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 285,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 285,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 287,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 292,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 292,
                      'char' => 20,
                    ),
                    16 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 292,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 292,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'blob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 292,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 292,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 292,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 293,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 293,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 293,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 293,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 293,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 295,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 300,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 300,
                      'char' => 20,
                    ),
                    17 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 300,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 300,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 300,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 300,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 300,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 301,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 301,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIMESTAMP',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 301,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 301,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 301,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 303,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 308,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 308,
                      'char' => 20,
                    ),
                    18 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 308,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 308,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'time',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 308,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 308,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 308,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 309,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 309,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIME',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 309,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 309,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 309,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 311,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 316,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 316,
                      'char' => 20,
                    ),
                    19 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 316,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 316,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'json',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 316,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 316,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 316,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 317,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 317,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_JSON',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 317,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 317,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 317,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 319,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 324,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 324,
                      'char' => 20,
                    ),
                    20 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 324,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 324,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'longtext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 324,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 324,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 324,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 325,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 325,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 325,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 325,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 325,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 327,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 332,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 332,
                      'char' => 20,
                    ),
                    21 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 332,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 332,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumtext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 332,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 332,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 332,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 333,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 333,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 333,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 333,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 333,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 335,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 340,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 340,
                      'char' => 20,
                    ),
                    22 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 340,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 340,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinytext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 340,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 340,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 340,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 341,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 341,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 341,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 341,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 341,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 343,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 348,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 348,
                      'char' => 20,
                    ),
                    23 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 348,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 348,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'text',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 348,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 348,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 348,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 349,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 349,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 349,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 349,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 349,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 351,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 356,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 356,
                      'char' => 20,
                    ),
                    24 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 356,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 356,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'varchar',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 356,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 356,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 356,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'definition',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 357,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 357,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 357,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 357,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 357,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 359,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 364,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 364,
                      'char' => 20,
                    ),
                    25 => 
                    array (
                      'type' => 'case',
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 364,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 364,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'char',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 364,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 364,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 364,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 365,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 365,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 365,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 365,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 365,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 367,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 372,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 372,
                      'char' => 23,
                    ),
                    26 => 
                    array (
                      'type' => 'default',
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 373,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 373,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 373,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 373,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 373,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 375,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 376,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 376,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 382,
                  'char' => 14,
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
                          'type' => 'variable',
                          'value' => 'columnType',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 382,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 382,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '(',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 382,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 382,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 382,
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
                          'operator' => 'assign',
                          'variable' => 'matches',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 383,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 383,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 385,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'definition',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 385,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'type',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 385,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 385,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 385,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'TYPE_ENUM',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 385,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 385,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 385,
                        'char' => 58,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 386,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
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
                                      'value' => 'columnType',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 386,
                                      'char' => 61,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 386,
                                    'char' => 61,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '5',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 386,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 386,
                                    'char' => 64,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '-1',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 386,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 386,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 386,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 386,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 387,
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
                            'type' => 'fcall',
                            'name' => 'preg_match',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sizePattern',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 387,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 387,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnType',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 387,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 387,
                                'char' => 60,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'matches',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 387,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 387,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 387,
                            'char' => 71,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'matchOne',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 388,
                                  'char' => 51,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'matches',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 388,
                                    'char' => 47,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 388,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 388,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 388,
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
                                      'assign-type' => 'array-index',
                                      'operator' => 'assign',
                                      'variable' => 'definition',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'size',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                          'line' => 389,
                                          'char' => 44,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'cast',
                                        'left' => 'int',
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'matchOne',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                          'line' => 389,
                                          'char' => 62,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                        'line' => 389,
                                        'char' => 62,
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 389,
                                      'char' => 62,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 390,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 392,
                              'char' => 22,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'matchTwo',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 392,
                                  'char' => 51,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'matches',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 392,
                                    'char' => 47,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 392,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 392,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
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
                                      'assign-type' => 'array-index',
                                      'operator' => 'assign',
                                      'variable' => 'definition',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'scale',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                          'line' => 393,
                                          'char' => 45,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'cast',
                                        'left' => 'int',
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'matchTwo',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                          'line' => 393,
                                          'char' => 63,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                        'line' => 393,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 393,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 394,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 395,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 396,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 396,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 401,
                  'char' => 14,
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
                          'type' => 'variable',
                          'value' => 'columnType',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 401,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 401,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'unsigned',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 401,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 401,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 401,
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
                              'value' => 'unsigned',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 402,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 402,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 402,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 403,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 408,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'oldColumn',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 408,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 408,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 408,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'first',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 409,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 409,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 409,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 410,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'after',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 411,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'oldColumn',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 411,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 411,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 412,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 417,
                  'char' => 14,
                ),
                6 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 417,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '3',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 417,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 417,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'PRI',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 417,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 417,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'primary',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 418,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 418,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 418,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 419,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 424,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 424,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 424,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 424,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'NO',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 424,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 424,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'notNull',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 425,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 425,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 425,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 426,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 431,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 431,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '5',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 431,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 431,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'auto_increment',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 431,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 431,
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
                              'value' => 'autoIncrement',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 432,
                              'char' => 45,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 432,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 432,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 433,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 438,
                  'char' => 14,
                ),
                9 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 438,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '4',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 438,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 438,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 438,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 438,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'default',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 439,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 439,
                              'char' => 48,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '4',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 439,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 439,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 439,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 440,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 445,
                  'char' => 15,
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
                      'variable' => 'columnName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 445,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 445,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 445,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 445,
                      'char' => 38,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'columns',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Column',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'columnName',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 446,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 446,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 446,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 446,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 446,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 446,
                      'char' => 63,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'oldColumn',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnName',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 447,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 447,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 448,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 450,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 450,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 451,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of Phalcon\\Db\\Column objects describing a table
     *
     * ```php
     * print_r(
     *     $connection->describeColumns("posts")
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ColumnInterface',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 88,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 88,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 87,
          'last-line' => 461,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 462,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 462,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 462,
              'char' => 73,
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
                  'variable' => 'indexes',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'keyName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'indexType',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'indexObjects',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 61,
                ),
                5 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 70,
                ),
                6 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 464,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 466,
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
                  'variable' => 'indexes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 466,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 466,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 468,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 468,
                  'char' => 27,
                ),
                'name' => 'fetchAll',
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
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 468,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 468,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 468,
                        'char' => 51,
                      ),
                      'name' => 'describeIndexes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 468,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 468,
                          'char' => 73,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 468,
                            'char' => 81,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 468,
                          'char' => 81,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 468,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 468,
                    'char' => 82,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Db',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 468,
                        'char' => 99,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_ASSOC',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 468,
                        'char' => 99,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 468,
                      'char' => 99,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 468,
                    'char' => 99,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 468,
                'char' => 101,
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
                      'variable' => 'keyName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 469,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'Key_name',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 469,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 469,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 469,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 470,
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
                      'variable' => 'indexType',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 470,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'Index_type',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 470,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 470,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 470,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 472,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'indexes',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 472,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 472,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 472,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 472,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 472,
                    'char' => 40,
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
                          'variable' => 'indexes',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'keyName',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 473,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 473,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 473,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 474,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 476,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexes',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 476,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'keyName',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 476,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 476,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 476,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 476,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 476,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 476,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 477,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 477,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 478,
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
                          'operator' => 'assign',
                          'variable' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'indexes',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 479,
                                'char' => 38,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'keyName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 479,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 479,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 479,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 479,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 479,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 480,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 482,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'columns',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 482,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'Column_name',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 482,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 482,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 482,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 483,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'indexes',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 483,
                          'char' => 32,
                        ),
                        1 => 
                        array (
                          'type' => 'string',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 483,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 483,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 483,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 485,
                  'char' => 14,
                ),
                6 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyName',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 485,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'PRIMARY',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 485,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 485,
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
                          'variable' => 'indexes',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'keyName',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 486,
                              'char' => 36,
                            ),
                            1 => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 486,
                              'char' => 42,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'PRIMARY',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 486,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 486,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 487,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'indexType',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 487,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'FULLTEXT',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 487,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 487,
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
                              'variable' => 'indexes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'keyName',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 488,
                                  'char' => 36,
                                ),
                                1 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 488,
                                  'char' => 42,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'FULLTEXT',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 488,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 488,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 489,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 489,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'index',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 489,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'Non_unique',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 489,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 489,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 489,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 489,
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
                              'variable' => 'indexes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'keyName',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 490,
                                  'char' => 36,
                                ),
                                1 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 490,
                                  'char' => 42,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'UNIQUE',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 490,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 490,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 491,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 491,
                      'char' => 18,
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
                          'variable' => 'indexes',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'keyName',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 492,
                              'char' => 36,
                            ),
                            1 => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 492,
                              'char' => 42,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 492,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 492,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 493,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 494,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 496,
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
                  'variable' => 'indexObjects',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 496,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 496,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 498,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'indexes',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 498,
                'char' => 36,
              ),
              'key' => 'name',
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'indexObjects',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 499,
                          'char' => 34,
                        ),
                      ),
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
                              'value' => 'name',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 500,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 500,
                            'char' => 21,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'index',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 501,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'columns',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 501,
                                'char' => 30,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 501,
                              'char' => 31,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 501,
                            'char' => 31,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'index',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 502,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'type',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 502,
                                'char' => 27,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 503,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 503,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 503,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 503,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 504,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 506,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'indexObjects',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 506,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 507,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lists table indexes
     *
     * ```php
     * print_r(
     *     $connection->describeIndexes("robots_parts")
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'IndexInterface',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 463,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 463,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 463,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 462,
          'last-line' => 517,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 518,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 518,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 518,
              'char' => 76,
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
                  'variable' => 'references',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 520,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 520,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'arrayReference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 520,
                  'char' => 50,
                ),
                3 => 
                array (
                  'variable' => 'constraintName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 520,
                  'char' => 66,
                ),
                4 => 
                array (
                  'variable' => 'referenceObjects',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 521,
                  'char' => 29,
                ),
                5 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 521,
                  'char' => 35,
                ),
                6 => 
                array (
                  'variable' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 521,
                  'char' => 53,
                ),
                7 => 
                array (
                  'variable' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 521,
                  'char' => 70,
                ),
                8 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 521,
                  'char' => 79,
                ),
                9 => 
                array (
                  'variable' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 522,
                  'char' => 30,
                ),
                10 => 
                array (
                  'variable' => 'referenceUpdate',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 522,
                  'char' => 47,
                ),
                11 => 
                array (
                  'variable' => 'referenceDelete',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 522,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 524,
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
                  'variable' => 'references',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 524,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 524,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 526,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 526,
                  'char' => 31,
                ),
                'name' => 'fetchAll',
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
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 526,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 526,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 526,
                        'char' => 55,
                      ),
                      'name' => 'describeReferences',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 526,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 526,
                          'char' => 80,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 526,
                            'char' => 88,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 526,
                          'char' => 88,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 526,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 526,
                    'char' => 89,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Db',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 526,
                        'char' => 104,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_NUM',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 526,
                        'char' => 104,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 526,
                      'char' => 104,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 526,
                    'char' => 104,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 526,
                'char' => 106,
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
                      'variable' => 'constraintName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reference',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 528,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 528,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 528,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 528,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 530,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'references',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 530,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'constraintName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 530,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 530,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 530,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 530,
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
                          'operator' => 'assign',
                          'variable' => 'referencedSchema',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 531,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '3',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 531,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 531,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 531,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 532,
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
                          'variable' => 'referencedTable',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 532,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '4',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 532,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 532,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 532,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 533,
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
                          'variable' => 'referenceUpdate',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 533,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '6',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 533,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 533,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 533,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 534,
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
                          'variable' => 'referenceDelete',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 534,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '7',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 534,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 534,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 534,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 535,
                      'char' => 19,
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
                          'variable' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 535,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 535,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 536,
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
                          'variable' => 'referencedColumns',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 536,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 536,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 537,
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
                          'operator' => 'assign',
                          'variable' => 'referencedSchema',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 538,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 538,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 538,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 538,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 538,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 538,
                          'char' => 85,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 539,
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
                          'variable' => 'referencedTable',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 539,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 539,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 539,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 539,
                              'char' => 83,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 539,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 539,
                          'char' => 84,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 540,
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
                          'variable' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 540,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 540,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 540,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 540,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 540,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 540,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 541,
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
                          'variable' => 'referencedColumns',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 541,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 541,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 541,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 541,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 541,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 541,
                          'char' => 86,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 542,
                      'char' => 19,
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
                          'variable' => 'referenceUpdate',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 542,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 542,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 542,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'onUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 542,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 542,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 542,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 543,
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
                          'variable' => 'referenceDelete',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'references',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 543,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                'line' => 543,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 543,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'onDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 543,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 543,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 543,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 544,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 546,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'columns',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reference',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 546,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 546,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 546,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 546,
                      'char' => 41,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'referencedColumns',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reference',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 547,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '5',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 547,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 547,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 547,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 549,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'references',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'constraintName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 549,
                          'char' => 42,
                        ),
                      ),
                      'expr' => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 550,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 550,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 550,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 551,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 551,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 551,
                            'char' => 52,
                          ),
                          2 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 552,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 552,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 552,
                            'char' => 44,
                          ),
                          3 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 553,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 553,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 553,
                            'char' => 54,
                          ),
                          4 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'onUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 554,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referenceUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 554,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 554,
                            'char' => 52,
                          ),
                          5 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'onDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 555,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referenceDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 556,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 556,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 556,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 556,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 557,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 559,
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
                  'variable' => 'referenceObjects',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 559,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 559,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 560,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'references',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 560,
                'char' => 48,
              ),
              'key' => 'name',
              'value' => 'arrayReference',
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'referenceObjects',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                          'line' => 561,
                          'char' => 38,
                        ),
                      ),
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
                              'value' => 'name',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 562,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 562,
                            'char' => 21,
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
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 564,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 564,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedSchema',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 564,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 564,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 564,
                                  'char' => 73,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedTable',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 565,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 565,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedTable',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 565,
                                      'char' => 71,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 565,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 565,
                                  'char' => 72,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'columns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 566,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 566,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'columns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 566,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 566,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 566,
                                  'char' => 64,
                                ),
                                3 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedColumns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 567,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 567,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedColumns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 567,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 567,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 567,
                                  'char' => 74,
                                ),
                                4 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'onUpdate',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 568,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 568,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'onUpdate',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 568,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 568,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 568,
                                  'char' => 65,
                                ),
                                5 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'onDelete',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 569,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 569,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'onDelete',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                      'line' => 569,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                    'line' => 570,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                                  'line' => 570,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                              'line' => 571,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                            'line' => 571,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                        'line' => 571,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 571,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 572,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 574,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'referenceObjects',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 574,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 575,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lists table references
     *
     *```php
     * print_r(
     *     $connection->describeReferences("robots_parts")
     * );
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ReferenceInterface',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                  'line' => 519,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 519,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 519,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 518,
          'last-line' => 579,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getDsnDefaults',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'charset',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 584,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'utf8mb4',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                      'line' => 585,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                    'line' => 585,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 585,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
              'line' => 586,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns PDO adapter DSN defaults as a key-value map.
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
                'line' => 581,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
            'line' => 581,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
          'line' => 580,
          'last-line' => 587,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Mysql.zep',
    'line' => 40,
    'char' => 5,
  ),
);