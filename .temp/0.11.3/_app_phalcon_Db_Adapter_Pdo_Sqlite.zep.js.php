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
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Adapter\\Pdo',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 14,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 15,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 17,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 18,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 19,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\RawValue',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 20,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
        'name' => 'Phalcon\\Db\\Reference',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 21,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
    'line' => 22,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\ReferenceInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
        'line' => 22,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
    'line' => 36,
    'char' => 2,
  ),
  12 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Specific functions for the Sqlite database system
 *
 * ```php
 * use Phalcon\\Db\\Adapter\\Pdo\\Sqlite;
 *
 * $connection = new Sqlite(
 *     [
 *         "dbname" => "/tmp/test.sqlite",
 *     ]
 * );
 * ```
 *',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
    'line' => 37,
    'char' => 5,
  ),
  13 => 
  array (
    'type' => 'class',
    'name' => 'Sqlite',
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
            'value' => 'sqlite',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 42,
            'char' => 35,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 46,
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
            'value' => 'sqlite',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 47,
            'char' => 28,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 51,
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
              'name' => 'descriptor',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 52,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 54,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'charset',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 54,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 54,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 54,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'trigger_error',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Sqlite does not allow the charset to be changed in the DSN.',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 57,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 57,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 57,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 58,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 60,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'descriptor',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 60,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 60,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 60,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor for Phalcon\\Db\\Adapter\\Pdo\\Sqlite
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 52,
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
          'name' => 'connect',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'descriptor',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 67,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 67,
              'char' => 52,
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
                  'variable' => 'dbname',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 69,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 71,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'descriptor',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 71,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 71,
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
                      'variable' => 'descriptor',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'array',
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 72,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'descriptor',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 72,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 72,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 72,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 72,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 73,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 75,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'dbname',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 75,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'dbname',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 75,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 75,
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
                      'variable' => 'descriptor',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'dsn',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 76,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dbname',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 76,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 76,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 78,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'descriptor',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 78,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'dbname',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 78,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 78,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
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
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'descriptor',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 79,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'dsn',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 79,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 79,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 79,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 79,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 79,
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
                              'value' => 'The database must be specified with either \'dbname\' or \'dsn\'.',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 82,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 82,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 82,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 83,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 85,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 85,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'connect',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'descriptor',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 85,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 85,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 85,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * This method is automatically called in Phalcon\\Db\\Adapter\\Pdo
     * constructor. Call it when you need to restore a database connection.
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 67,
          'last-line' => 96,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 97,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 97,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 97,
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
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'columnType',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'fields',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'oldColumn',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 99,
                  'char' => 70,
                ),
                6 => 
                array (
                  'variable' => 'sizePattern',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 100,
                  'char' => 24,
                ),
                7 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 100,
                  'char' => 33,
                ),
                8 => 
                array (
                  'variable' => 'matchOne',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 100,
                  'char' => 43,
                ),
                9 => 
                array (
                  'variable' => 'matchTwo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 100,
                  'char' => 53,
                ),
                10 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 100,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 102,
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
                  'variable' => 'oldColumn',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 102,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 102,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 103,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 103,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 105,
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
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 105,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 105,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
                  'variable' => 'fields',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 110,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 111,
                              'char' => 18,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'dialect',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 111,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 111,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 111,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 111,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 111,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 111,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 111,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 111,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 113,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'FETCH_NUM',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 113,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 113,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 113,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 113,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 113,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 115,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'fields',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 115,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 121,
                              'char' => 25,
                            ),
                            'value' => 
                            array (
                              'type' => 'static-constant-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Column',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 122,
                                'char' => 13,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'BIND_PARAM_STR',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 122,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 122,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 122,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 122,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 122,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 128,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 128,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 128,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 128,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 128,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 143,
                  'char' => 14,
                ),
                2 => 
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 143,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 143,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'bigint',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 143,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 143,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 143,
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
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 147,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'Column',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 147,
                              'char' => 63,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_BIGINTEGER',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 147,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 147,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 147,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 148,
                              'char' => 41,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 148,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 148,
                          'char' => 49,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 149,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 149,
                              'char' => 66,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'BIND_PARAM_INT',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 149,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 149,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 149,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 150,
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
                        'type' => 'or',
                        'left' => 
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 150,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 150,
                              'char' => 39,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'int',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 150,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 150,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 150,
                          'char' => 47,
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
                                'type' => 'variable',
                                'value' => 'columnType',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 150,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 150,
                              'char' => 66,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'INT',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 150,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 150,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 150,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 150,
                        'char' => 73,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 154,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 154,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_INTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 154,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 154,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 154,
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
                                  'value' => 'isNumeric',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 155,
                                  'char' => 41,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 155,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 155,
                              'char' => 49,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 156,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 156,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 156,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 156,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 156,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 158,
                          'char' => 18,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 158,
                              'char' => 25,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '5',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 158,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 158,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'definition',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'autoIncrement',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 159,
                                      'char' => 49,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 159,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 159,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 160,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 161,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 161,
                      'char' => 20,
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
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 161,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 161,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyint(1)',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 161,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 161,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 161,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 165,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 165,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BOOLEAN',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 165,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 165,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 165,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 166,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 166,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BOOL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 166,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 166,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 166,
                              'char' => 67,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'columnType',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'boolean',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 167,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 167,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 172,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 172,
                      'char' => 20,
                    ),
                    2 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 172,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 172,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'enum',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 172,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 172,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 172,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 176,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 176,
                                  'char' => 57,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 176,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 176,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 176,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 181,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 181,
                      'char' => 20,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 181,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 181,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'datetime',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 181,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 181,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 181,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 185,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 185,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATETIME',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 185,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 185,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 185,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 186,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 186,
                      'char' => 20,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 186,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 186,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'date',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 186,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 186,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 186,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 190,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 190,
                                  'char' => 57,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATE',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 190,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 190,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 190,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 195,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 195,
                      'char' => 20,
                    ),
                    5 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 195,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 195,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'decimal',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 195,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 195,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 195,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 199,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 199,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 199,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 199,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 199,
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
                                  'value' => 'isNumeric',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 200,
                                  'char' => 41,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 200,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 200,
                              'char' => 49,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 201,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 201,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 201,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 201,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 201,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 202,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 202,
                      'char' => 20,
                    ),
                    6 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 202,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 202,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'float',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 202,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 202,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 202,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 206,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 206,
                                  'char' => 58,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_FLOAT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 206,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 206,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 206,
                              'char' => 58,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 207,
                                  'char' => 41,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 207,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 207,
                              'char' => 49,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 208,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 208,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 208,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 208,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 208,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 213,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 213,
                      'char' => 20,
                    ),
                    7 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 213,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 213,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 213,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 213,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 213,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 217,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 217,
                                  'char' => 62,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIMESTAMP',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 217,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 217,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 217,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 222,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 222,
                      'char' => 20,
                    ),
                    8 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 222,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 222,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'varchar',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 222,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 222,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 226,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 226,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 226,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 226,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 226,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 227,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 227,
                      'char' => 20,
                    ),
                    9 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 227,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 227,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'char',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 227,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 227,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 227,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 231,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 231,
                                  'char' => 57,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 231,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 231,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 231,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 232,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 232,
                      'char' => 20,
                    ),
                    10 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 232,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 232,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'text',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 232,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 232,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 232,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 236,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 236,
                                  'char' => 57,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 236,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 236,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 236,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 238,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 238,
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
                          'variable' => 'definition',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 242,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'Column',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 242,
                              'char' => 60,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'TYPE_VARCHAR',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 242,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 242,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 242,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 243,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 249,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 249,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 249,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '(',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 249,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 249,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 249,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 250,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 250,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 252,
                      'char' => 18,
                    ),
                    1 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 252,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 252,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'columnType',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 252,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 252,
                            'char' => 54,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'matches',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 252,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 252,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 252,
                        'char' => 65,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 253,
                              'char' => 51,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'matches',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 253,
                                'char' => 47,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 253,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 253,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 253,
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
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 254,
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
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 254,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 254,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 254,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 255,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 256,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 256,
                              'char' => 51,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'matches',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 256,
                                'char' => 47,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '2',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 256,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 256,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 256,
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
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 257,
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
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 257,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 257,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 257,
                                  'char' => 63,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 258,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 259,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 260,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 265,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 265,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 265,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'unsigned',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 265,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 265,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 265,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 266,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 266,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 266,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 267,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 272,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 272,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 272,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 272,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 273,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 273,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 273,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 274,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 275,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'oldColumn',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 275,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 275,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 276,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 281,
                  'char' => 14,
                ),
                6 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 281,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '5',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 281,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 281,
                    'char' => 25,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 282,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 282,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 282,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 283,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 288,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 288,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '3',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 288,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 288,
                    'char' => 25,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 289,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 289,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 289,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 290,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 296,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strcasecmp',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 296,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '4',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 296,
                                'char' => 34,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 296,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 296,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'null',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 296,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 296,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 296,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 296,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 296,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 296,
                          'char' => 56,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 296,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 296,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 296,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 296,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 296,
                    'char' => 64,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 297,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'preg_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/^\'|\'$/',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 298,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 298,
                                'char' => 28,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 299,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 299,
                                'char' => 21,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'field',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 300,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '4',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 300,
                                    'char' => 28,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 301,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 301,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 301,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 301,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 302,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 307,
                  'char' => 15,
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
                      'variable' => 'columnName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 307,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 307,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 307,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 307,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 308,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 308,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 308,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 308,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 308,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 308,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 309,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 309,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 310,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 312,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 312,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 313,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 98,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 97,
          'last-line' => 323,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 324,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 324,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 324,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'keyName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'indexObjects',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 50,
                ),
                4 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 326,
                  'char' => 65,
                ),
                6 => 
                array (
                  'variable' => 'describeIndexes',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 327,
                  'char' => 28,
                ),
                7 => 
                array (
                  'variable' => 'describeIndex',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 327,
                  'char' => 43,
                ),
                8 => 
                array (
                  'variable' => 'indexSql',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 327,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 329,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 329,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 329,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 331,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 331,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 331,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 331,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 331,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 331,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 331,
                          'char' => 73,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 331,
                            'char' => 81,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 331,
                          'char' => 81,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 331,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 331,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 331,
                        'char' => 99,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_ASSOC',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 331,
                        'char' => 99,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 331,
                      'char' => 99,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 331,
                    'char' => 99,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 331,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 332,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 332,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 332,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 332,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 334,
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
                          'value' => 'indexes',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 334,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 334,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 334,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 334,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 334,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 335,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 335,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 335,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 336,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 338,
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
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'indexes',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 338,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'keyName',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 338,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 338,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 338,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 338,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 338,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 338,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 339,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 339,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 340,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 341,
                                'char' => 38,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'keyName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 341,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 341,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 341,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 341,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 341,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 342,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 344,
                  'char' => 15,
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
                      'variable' => 'describeIndexes',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 344,
                          'char' => 40,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 345,
                                  'char' => 22,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'dialect',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 345,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 345,
                                'char' => 31,
                              ),
                              'name' => 'describeIndex',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'keyName',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 345,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 345,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 345,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 345,
                            'char' => 54,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 347,
                                'char' => 13,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'FETCH_ASSOC',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 347,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 347,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 347,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 347,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 347,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 349,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'describeIndexes',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 349,
                    'char' => 50,
                  ),
                  'value' => 'describeIndex',
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'describeIndex',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 350,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 350,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 350,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 350,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 351,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 353,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 353,
                          'char' => 32,
                        ),
                        1 => 
                        array (
                          'type' => 'string',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 353,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 353,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 353,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 355,
                  'char' => 15,
                ),
                6 => 
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
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 355,
                          'char' => 33,
                        ),
                        'name' => 'fetchColumn',
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 356,
                                  'char' => 22,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'dialect',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 356,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 356,
                                'char' => 31,
                              ),
                              'name' => 'listIndexesSql',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'table',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 356,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 356,
                                  'char' => 52,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'schema',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 356,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 356,
                                  'char' => 60,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'keyName',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 356,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 356,
                                  'char' => 69,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 357,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 357,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 357,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 357,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 359,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 359,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'unique',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 359,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 359,
                    'char' => 30,
                  ),
                  'statements' => 
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
                              'type' => 'string',
                              'value' => '# UNIQUE #i',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 360,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 360,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'indexSql',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 360,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 360,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 360,
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
                              'variable' => 'indexes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'keyName',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 361,
                                  'char' => 40,
                                ),
                                1 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 361,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'UNIQUE',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 361,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 361,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 362,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'indexes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'keyName',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 363,
                                  'char' => 40,
                                ),
                                1 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 363,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'PRIMARY',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 363,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 363,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 364,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 365,
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
                          'variable' => 'indexes',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'keyName',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 366,
                              'char' => 36,
                            ),
                            1 => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 366,
                              'char' => 42,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 366,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 366,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 367,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 368,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 370,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 370,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 370,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 372,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'indexes',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 372,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 373,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 374,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 374,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 375,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'columns',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 375,
                                'char' => 30,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 375,
                              'char' => 31,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 375,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 376,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'type',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 376,
                                'char' => 27,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 377,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 377,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 377,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 377,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 378,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 380,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'indexObjects',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 380,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 381,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 325,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 325,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 325,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 324,
          'last-line' => 385,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 386,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 386,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 386,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 388,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 388,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'arrayReference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 388,
                  'char' => 50,
                ),
                3 => 
                array (
                  'variable' => 'constraintName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 388,
                  'char' => 66,
                ),
                4 => 
                array (
                  'variable' => 'referenceObjects',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 389,
                  'char' => 29,
                ),
                5 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 389,
                  'char' => 35,
                ),
                6 => 
                array (
                  'variable' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 389,
                  'char' => 53,
                ),
                7 => 
                array (
                  'variable' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 389,
                  'char' => 70,
                ),
                8 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 389,
                  'char' => 79,
                ),
                9 => 
                array (
                  'variable' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 390,
                  'char' => 30,
                ),
                10 => 
                array (
                  'variable' => 'number',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 390,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 392,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 392,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 392,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 394,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 394,
                  'char' => 39,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 394,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 394,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 394,
                        'char' => 63,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 394,
                            'char' => 88,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 394,
                          'char' => 88,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 394,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 394,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 394,
                      'char' => 97,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 394,
                    'char' => 97,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 394,
                        'char' => 112,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_NUM',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 394,
                        'char' => 112,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 394,
                      'char' => 112,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 394,
                    'char' => 112,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 394,
                'char' => 114,
              ),
              'key' => 'number',
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'foreign_key_',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 395,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'number',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 395,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 395,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 395,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 397,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 397,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'constraintName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 397,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 397,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 397,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 397,
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
                            'type' => 'null',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 398,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 398,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
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
                          'operator' => 'assign',
                          'variable' => 'referencedTable',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reference',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 399,
                              'char' => 48,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 399,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 399,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 399,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 400,
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
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 400,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 400,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 401,
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
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 401,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 401,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 402,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 403,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 403,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 403,
                              'char' => 66,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 403,
                              'char' => 83,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 403,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 403,
                          'char' => 84,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 404,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 404,
                                'char' => 49,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 404,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 404,
                              'char' => 65,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 404,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 404,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 404,
                          'char' => 82,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 405,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 405,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 405,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 405,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 405,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 405,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 405,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 406,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 406,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                'line' => 406,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 406,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 406,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 406,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 406,
                          'char' => 86,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 407,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 409,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 409,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '3',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 409,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 409,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 409,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 410,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 410,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 410,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 410,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 412,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 412,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 413,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 413,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 413,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 414,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 414,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 414,
                            'char' => 52,
                          ),
                          2 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 415,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 415,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 415,
                            'char' => 44,
                          ),
                          3 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 416,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 417,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 417,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 417,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 417,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 418,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 420,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 420,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 420,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 422,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'references',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 422,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                          'line' => 423,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 424,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 424,
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
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 426,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 426,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedSchema',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 426,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 426,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 426,
                                  'char' => 73,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedTable',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 427,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 427,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedTable',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 427,
                                      'char' => 71,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 427,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 427,
                                  'char' => 72,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'columns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 428,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 428,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'columns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 428,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 428,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 428,
                                  'char' => 64,
                                ),
                                3 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedColumns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 429,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 429,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedColumns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                      'line' => 429,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                    'line' => 430,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                                  'line' => 430,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                              'line' => 431,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                            'line' => 431,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                        'line' => 431,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 431,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 432,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 434,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'referenceObjects',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 434,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 435,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lists table references
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 387,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 387,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 387,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 386,
          'last-line' => 455,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultValue',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'RawValue',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'NULL',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                      'line' => 458,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                    'line' => 458,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 458,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 459,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the default value to make the RBDM use the default value declared
     * in the table definition
     *
     *```php
     * // Inserting a new robot with a valid default value for the column \'year\'
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         "Astro Boy",
     *         $connection->getDefaultValue(),
     *     ],
     *     [
     *         "name",
     *         "year",
     *     ]
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
                  'value' => 'RawValue',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                  'line' => 457,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 457,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 457,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 456,
          'last-line' => 464,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useExplicitIdValue',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 467,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 468,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the database system requires an explicit value for identity
     * columns
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 466,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 466,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 465,
          'last-line' => 472,
          'char' => 19,
        ),
        7 => 
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
                'type' => 'empty-array',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 475,
                'char' => 18,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
              'line' => 476,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
                'line' => 474,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
            'line' => 474,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
          'line' => 473,
          'last-line' => 477,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
      'line' => 37,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Sqlite.zep',
    'line' => 37,
    'char' => 5,
  ),
);