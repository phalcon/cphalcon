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
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Adapter\\Pdo',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 14,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 15,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 17,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\RawValue',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 18,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\Reference',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 19,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'name' => 'Phalcon\\Db\\ReferenceInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 20,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
        'name' => 'Throwable',
        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
        'line' => 21,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
    'line' => 39,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Specific functions for the Postgresql database system
 *
 * ```php
 * use Phalcon\\Db\\Adapter\\Pdo\\Postgresql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 5432,
 *     "username" => "postgres",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Postgresql($config);
 * ```
 *',
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
    'line' => 40,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'Postgresql',
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
            'value' => 'postgresql',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 45,
            'char' => 39,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
            'value' => 'pgsql',
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 50,
            'char' => 27,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 55,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 57,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'charset',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 57,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 57,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 57,
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
                          'value' => 'Postgres does not allow the charset to be changed in the DSN.',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 60,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 60,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 60,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 61,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 63,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 63,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 63,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 63,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor for Phalcon\\Db\\Adapter\\Pdo\\Postgresql
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 55,
          'last-line' => 69,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 70,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 70,
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
                  'variable' => 'schema',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 72,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 72,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'status',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 72,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 74,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 74,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 74,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 75,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'descriptor',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 75,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 75,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 75,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 75,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 78,
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
                  'value' => 'schema',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 78,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 78,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'schema',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 78,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 78,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 78,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'descriptor',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 79,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'schema',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 79,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 79,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 80,
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
                      'variable' => 'schema',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 81,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 81,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 84,
              'char' => 10,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 84,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'password',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 84,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 84,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 84,
                'char' => 39,
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
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'descriptor',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 85,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'password',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 85,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 85,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 85,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 85,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 85,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strlen',
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
                                'value' => 'descriptor',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 85,
                                'char' => 74,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'password',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 85,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 85,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 85,
                            'char' => 84,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 85,
                        'char' => 87,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 85,
                        'char' => 91,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 85,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 85,
                    'char' => 91,
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
                              'value' => 'password',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 86,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 86,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 86,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 87,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 90,
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
                  'variable' => 'status',
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 90,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 90,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 90,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 90,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 92,
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
                    'value' => 'schema',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 92,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 92,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 92,
                'char' => 26,
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
                            'value' => 'SET search_path TO \'',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 93,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 93,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 93,
                          'char' => 53,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '\'',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 93,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 93,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 93,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 95,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 95,
                      'char' => 18,
                    ),
                    'name' => 'execute',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sql',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 95,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 95,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 95,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 98,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'status',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 98,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 99,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 70,
          'last-line' => 103,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 104,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 104,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 104,
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
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 106,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'queries',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 106,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 106,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'exception',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 106,
                  'char' => 43,
                ),
                4 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 106,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 108,
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
                      'value' => 'columns',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 108,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 108,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 108,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 108,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 108,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
                          'value' => 'The table must contain at least one column',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 109,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 109,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 109,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 110,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 112,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 112,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 112,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 112,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 112,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 112,
                'char' => 37,
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
                          'value' => 'The table must contain at least one column',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 113,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 113,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 113,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 116,
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 116,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dialect',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 116,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 116,
                      'char' => 33,
                    ),
                    'name' => 'createTable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tableName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 116,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 116,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 116,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 116,
                        'char' => 67,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'definition',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 116,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 116,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 116,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 116,
                  'char' => 80,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 118,
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
                  'variable' => 'queries',
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
                          'value' => ';',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 118,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 118,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sql',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 118,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 118,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 118,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 118,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 120,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
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
                        'value' => 'queries',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 120,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 120,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 120,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 120,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 120,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'try-catch',
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 122,
                          'char' => 22,
                        ),
                        'name' => 'begin',
                        'call-type' => 3,
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 122,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 124,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'queries',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 124,
                        'char' => 38,
                      ),
                      'value' => 'query',
                      'reverse' => 0,
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
                              'value' => 'query',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 125,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 125,
                            'char' => 36,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 127,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 129,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 129,
                              'char' => 26,
                            ),
                            'name' => 'query',
                            'call-type' => 3,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'query',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 129,
                                    'char' => 41,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ';',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 129,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 129,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 129,
                                'char' => 44,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 129,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 130,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 132,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 132,
                          'char' => 29,
                        ),
                        'name' => 'commit',
                        'call-type' => 3,
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 132,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 133,
                      'char' => 13,
                    ),
                  ),
                  'catches' => 
                  array (
                    0 => 
                    array (
                      'classes' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'Throwable',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 133,
                          'char' => 30,
                        ),
                      ),
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 138,
                        'char' => 9,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 134,
                              'char' => 22,
                            ),
                            'name' => 'rollback',
                            'call-type' => 3,
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 134,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 136,
                          'char' => 21,
                        ),
                        1 => 
                        array (
                          'type' => 'throw',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'exception',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 136,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 137,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 138,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 138,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 139,
                      'char' => 25,
                    ),
                    'name' => 'execute',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'queries',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 139,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 139,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 139,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ';',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 139,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 139,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 139,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 139,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 140,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 142,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 142,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates a table
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 104,
          'last-line' => 153,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 154,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 154,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 154,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'columnType',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'fields',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'oldColumn',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 156,
                  'char' => 70,
                ),
                6 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 157,
                  'char' => 23,
                ),
                7 => 
                array (
                  'variable' => 'charSize',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 157,
                  'char' => 33,
                ),
                8 => 
                array (
                  'variable' => 'numericSize',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 157,
                  'char' => 46,
                ),
                9 => 
                array (
                  'variable' => 'numericScale',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 157,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 159,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 159,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 159,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 159,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 159,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 166,
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
                  'variable' => 'fields',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 166,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 167,
                              'char' => 18,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'dialect',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 167,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 167,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 167,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 167,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 167,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 167,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 167,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 167,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 169,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'FETCH_NUM',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 169,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 169,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 169,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 169,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 169,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 171,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'fields',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 171,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 177,
                              'char' => 25,
                            ),
                            'value' => 
                            array (
                              'type' => 'static-constant-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Column',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 178,
                                'char' => 13,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'BIND_PARAM_STR',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 178,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 178,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 178,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 178,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 178,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 184,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 184,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 184,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 184,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 184,
                      'char' => 38,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'charSize',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 185,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 185,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 185,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 185,
                      'char' => 36,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'numericSize',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 186,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '3',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 186,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 186,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 186,
                      'char' => 39,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'numericScale',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 187,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 187,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 187,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 187,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 201,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 201,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 205,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 205,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'boolean',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 205,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 205,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 205,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 209,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 209,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BOOLEAN',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 209,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 209,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 209,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 210,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 210,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 210,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 211,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 211,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BOOL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 211,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 211,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 211,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 213,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 218,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 218,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 218,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 218,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'bigint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 218,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 218,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 218,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 219,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 219,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIGINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 219,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 219,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 219,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 220,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 220,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 220,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 221,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 221,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 221,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 221,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 221,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 223,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 228,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 228,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 228,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 228,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 228,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 228,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 228,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 229,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 229,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 229,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 229,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 229,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 230,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 230,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 230,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 231,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 231,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 231,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 231,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 231,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 233,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 238,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 238,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 238,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 238,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'smallint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 238,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 238,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 238,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 239,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 239,
                                  'char' => 69,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_SMALLINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 239,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 239,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 239,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 240,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 240,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 240,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 241,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 241,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 241,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 241,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 241,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 243,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 248,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 248,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 248,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 248,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyint',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 248,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 248,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 248,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 252,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 252,
                                  'char' => 68,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYINTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 252,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 252,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 252,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 253,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 253,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 253,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 254,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 254,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 254,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 254,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 254,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 256,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 261,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 261,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 261,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 261,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'int',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 261,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 261,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 261,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 262,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 262,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_INTEGER',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 262,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 262,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 262,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 263,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 263,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 263,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 264,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 264,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 264,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 264,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 264,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 266,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 271,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 271,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 271,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 271,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'bit',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 271,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 271,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 271,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 272,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 272,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 272,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 272,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 272,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 273,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numericSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 273,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 273,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 275,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 280,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 280,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 280,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 280,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'enum',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 280,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 280,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 280,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 281,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 281,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_ENUM',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 281,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 281,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 281,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 283,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 288,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 288,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 288,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 288,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'datetime',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 288,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 288,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 288,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 289,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 289,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATETIME',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 289,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 289,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 289,
                              'char' => 65,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 290,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 290,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 290,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 292,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 297,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 297,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 297,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 297,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'date',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 297,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 297,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 297,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 298,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 298,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATE',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 298,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 298,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 298,
                              'char' => 61,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 299,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 299,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 299,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 301,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 307,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 307,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 307,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 307,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'decimal',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 307,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 307,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 307,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 308,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 308,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 308,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'numeric',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 308,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 308,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 308,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 309,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 309,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 309,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 309,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 310,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numericSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 310,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 310,
                              'char' => 55,
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
                                  'value' => 'isNumeric',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 311,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 311,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 311,
                              'char' => 53,
                            ),
                            3 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 312,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 312,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 312,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 312,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 312,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 314,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 319,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 319,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 319,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 319,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'double precision',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 319,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 319,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 319,
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
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 320,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 320,
                                  'char' => 63,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DOUBLE',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 320,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 320,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 320,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 321,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 321,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 321,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 322,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numericSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 322,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 322,
                              'char' => 55,
                            ),
                            3 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 323,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 323,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 323,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 323,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 323,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 325,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 330,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 330,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 330,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 330,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'float',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 330,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 330,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 330,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 331,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 331,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 331,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'real',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 331,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 331,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 331,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 332,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 332,
                                  'char' => 62,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_FLOAT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 332,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 332,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 332,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 333,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 333,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 333,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 334,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numericSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 334,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 334,
                              'char' => 55,
                            ),
                            3 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 335,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 335,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 335,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 335,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 335,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 337,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 342,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 342,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 342,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 342,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 342,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 342,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 342,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 343,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 343,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 343,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 343,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 343,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 345,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 350,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 350,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 350,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 350,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'longblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 350,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 350,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 350,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 351,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 351,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGBLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 351,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 351,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 351,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 353,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 358,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 358,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 358,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 358,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinyblob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 358,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 358,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 358,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 359,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 359,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYBLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 359,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 359,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 359,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 361,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 366,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 366,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 366,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 366,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'blob',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 366,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 366,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 366,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 367,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 367,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BLOB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 367,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 367,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 367,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 369,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 374,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 374,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 374,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 374,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 374,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 374,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 374,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 375,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 375,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIMESTAMP',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 375,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 375,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 375,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 377,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 382,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 382,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 382,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 382,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'time',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 382,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 382,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 382,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 383,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 383,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIME',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 383,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 383,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 383,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 385,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 390,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 390,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 390,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 390,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'jsonb',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 390,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 390,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 390,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 391,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 391,
                                  'char' => 62,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_JSONB',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 391,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 391,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 391,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 393,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 398,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 398,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 398,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 398,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'json',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 398,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 398,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 398,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 399,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 399,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_JSON',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 399,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 399,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 399,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 401,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 406,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 406,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 406,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 406,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'longtext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 406,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 406,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 406,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 407,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 407,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 407,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 407,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 407,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 409,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 414,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 414,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 414,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 414,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mediumtext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 414,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 414,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 414,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 415,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 415,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 415,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 415,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 415,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 417,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 422,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 422,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 422,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 422,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tinytext',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 422,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 422,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 422,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 423,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 423,
                                  'char' => 65,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYTEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 423,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 423,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 423,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 425,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 430,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 430,
                      'char' => 20,
                    ),
                    26 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 430,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 430,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'text',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 430,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 430,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 430,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 431,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 431,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TEXT',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 431,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 431,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 431,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 433,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 438,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 438,
                      'char' => 20,
                    ),
                    27 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 438,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 438,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'varying',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 438,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 438,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 438,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 439,
                      'char' => 20,
                    ),
                    28 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 439,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 439,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'varchar',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 439,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 439,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 439,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 440,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 440,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 440,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 440,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 440,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 441,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'charSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 441,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 441,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 443,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 448,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 448,
                      'char' => 20,
                    ),
                    29 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 448,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 448,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'char',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 448,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 448,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 448,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 449,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 449,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 449,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 449,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 449,
                              'char' => 61,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 450,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'charSize',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 450,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 450,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 452,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 457,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 457,
                      'char' => 20,
                    ),
                    30 => 
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 457,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 457,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'uuid',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 457,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 457,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 457,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 458,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 458,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 458,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 458,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 458,
                              'char' => 61,
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
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 459,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '36',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 459,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 459,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 461,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 466,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 466,
                      'char' => 23,
                    ),
                    31 => 
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 467,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 467,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 467,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 467,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 467,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 469,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 470,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 470,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 475,
                  'char' => 14,
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
                      'value' => 'oldColumn',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 475,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 475,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 475,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 476,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 476,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 476,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 477,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 478,
                              'char' => 37,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'oldColumn',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 478,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 478,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 479,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 484,
                  'char' => 14,
                ),
                4 => 
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 484,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '6',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 484,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 484,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'PRI',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 484,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 484,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 485,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 485,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 485,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 486,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 491,
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
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 491,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '5',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 491,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 491,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'NO',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 491,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 491,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 492,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 492,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 492,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 493,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 498,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 498,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '7',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 498,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 498,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'auto_increment',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 498,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 498,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 499,
                              'char' => 45,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 499,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 499,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 500,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 505,
                  'char' => 14,
                ),
                7 => 
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 505,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '9',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 505,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 505,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 505,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 505,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 506,
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
                                  'value' => '/^\'|\'?::[[:alnum:][:space:]]+$/',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 507,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 507,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 508,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 508,
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
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 509,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '9',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 509,
                                    'char' => 28,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 510,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 510,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 510,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 510,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 512,
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
                                  'value' => 'definition',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 512,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'default',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 512,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 512,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 512,
                              'char' => 50,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'null',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 512,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 512,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 512,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 512,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 512,
                        'char' => 63,
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
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 513,
                                  'char' => 43,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'null',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 513,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 513,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 514,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 515,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 520,
                  'char' => 15,
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
                      'variable' => 'columnName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 520,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 520,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 520,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 520,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 521,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 521,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 521,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 521,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 521,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 521,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 522,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 522,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 523,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 525,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 525,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 526,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 155,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 155,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 155,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 154,
          'last-line' => 536,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 537,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 537,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 537,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 539,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'reference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 539,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'arrayReference',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 539,
                  'char' => 50,
                ),
                3 => 
                array (
                  'variable' => 'constraintName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 539,
                  'char' => 66,
                ),
                4 => 
                array (
                  'variable' => 'referenceObjects',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 540,
                  'char' => 29,
                ),
                5 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 540,
                  'char' => 35,
                ),
                6 => 
                array (
                  'variable' => 'referencedSchema',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 540,
                  'char' => 53,
                ),
                7 => 
                array (
                  'variable' => 'referencedTable',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 540,
                  'char' => 70,
                ),
                8 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 540,
                  'char' => 79,
                ),
                9 => 
                array (
                  'variable' => 'referencedColumns',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 541,
                  'char' => 30,
                ),
                10 => 
                array (
                  'variable' => 'referenceUpdate',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 541,
                  'char' => 47,
                ),
                11 => 
                array (
                  'variable' => 'referenceDelete',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 541,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 543,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 543,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 543,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 545,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 545,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 545,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dialect',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 545,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 545,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 545,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 545,
                          'char' => 80,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'schema',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 545,
                            'char' => 88,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 545,
                          'char' => 88,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 545,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 545,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 545,
                        'char' => 104,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_NUM',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 545,
                        'char' => 104,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 545,
                      'char' => 104,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 545,
                    'char' => 104,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 545,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 546,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 546,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 546,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 546,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 548,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 548,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'constraintName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 548,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 548,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 548,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 548,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 549,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '3',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 549,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 549,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 549,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 550,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 550,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '4',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 550,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 550,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 550,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 551,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 551,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '6',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 551,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 551,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 551,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 552,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 552,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '7',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 552,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 552,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 552,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 553,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 553,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 553,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 554,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 554,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 554,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 555,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 556,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 556,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 556,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 556,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 556,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 556,
                          'char' => 85,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 557,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 557,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 557,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 557,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 557,
                              'char' => 83,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 557,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 557,
                          'char' => 84,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 558,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 558,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 558,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 558,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 558,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 558,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 558,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 559,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 559,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 559,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 559,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 559,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 559,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 559,
                          'char' => 86,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 560,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 560,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 560,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 560,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'onUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 560,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 560,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 560,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 561,
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
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 561,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'constraintName',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 561,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 561,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'onDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 561,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 561,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 561,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 562,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 564,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 564,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 564,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 564,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 564,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 565,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '5',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 565,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 565,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 565,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 567,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 567,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 568,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedSchema',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 568,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 568,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 569,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedTable',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 569,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 569,
                            'char' => 52,
                          ),
                          2 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 570,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'columns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 570,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 570,
                            'char' => 44,
                          ),
                          3 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 571,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referencedColumns',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 571,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 571,
                            'char' => 54,
                          ),
                          4 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'onUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 572,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referenceUpdate',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 572,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 572,
                            'char' => 52,
                          ),
                          5 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'onDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 573,
                              'char' => 35,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'referenceDelete',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 574,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 574,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 574,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 574,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 575,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 577,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 577,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 577,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 579,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'references',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 579,
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
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 580,
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
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 581,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 581,
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
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 583,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 583,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedSchema',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 583,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 583,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 583,
                                  'char' => 73,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedTable',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 584,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 584,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedTable',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 584,
                                      'char' => 71,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 584,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 584,
                                  'char' => 72,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'columns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 585,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 585,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'columns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 585,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 585,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 585,
                                  'char' => 64,
                                ),
                                3 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'referencedColumns',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 586,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 586,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'referencedColumns',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 586,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 586,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 586,
                                  'char' => 74,
                                ),
                                4 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'onUpdate',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 587,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 587,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'onUpdate',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 587,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 587,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 587,
                                  'char' => 65,
                                ),
                                5 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'onDelete',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 588,
                                    'char' => 39,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arrayReference',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 588,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'onDelete',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                      'line' => 588,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 589,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 589,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 590,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 590,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 590,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 590,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 591,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 593,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'referenceObjects',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 593,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 594,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 538,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 538,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 538,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 537,
          'last-line' => 615,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultIdValue',
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
                      'value' => 'DEFAULT',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 618,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 618,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 618,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 619,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the default identity value to be inserted in an identity column
     *
     *```php
     * // Inserting a new robot with a valid default value for the column \'id\'
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         $connection->getDefaultIdValue(),
     *         "Astro Boy",
     *         1952,
     *     ],
     *     [
     *         "id",
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 617,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 617,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 617,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 616,
          'last-line' => 623,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 624,
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
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 624,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 624,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 624,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 624,
                'char' => 129,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 624,
                'char' => 137,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 624,
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
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 626,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'queries',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 626,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 626,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'exception',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 626,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 628,
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 628,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dialect',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 628,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 628,
                      'char' => 33,
                    ),
                    'name' => 'modifyColumn',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tableName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 629,
                          'char' => 22,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 629,
                        'char' => 22,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schemaName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 630,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 630,
                        'char' => 23,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 631,
                          'char' => 19,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 631,
                        'char' => 19,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'currentColumn',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 633,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 633,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 633,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 633,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 635,
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
                  'variable' => 'queries',
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
                          'value' => ';',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 635,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 635,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sql',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 635,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 635,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 635,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 635,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 637,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
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
                        'value' => 'queries',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 637,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 637,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 637,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 637,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 637,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'try-catch',
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 639,
                          'char' => 22,
                        ),
                        'name' => 'begin',
                        'call-type' => 3,
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 639,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 641,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'queries',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 641,
                        'char' => 38,
                      ),
                      'value' => 'query',
                      'reverse' => 0,
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
                              'value' => 'query',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 642,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 642,
                            'char' => 36,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 644,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 646,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 646,
                              'char' => 26,
                            ),
                            'name' => 'query',
                            'call-type' => 3,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'query',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 646,
                                    'char' => 41,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ';',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                    'line' => 646,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                  'line' => 646,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 646,
                                'char' => 44,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 646,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 647,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 649,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 649,
                          'char' => 29,
                        ),
                        'name' => 'commit',
                        'call-type' => 3,
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 649,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 650,
                      'char' => 13,
                    ),
                  ),
                  'catches' => 
                  array (
                    0 => 
                    array (
                      'classes' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'Throwable',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 650,
                          'char' => 30,
                        ),
                      ),
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 655,
                        'char' => 9,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 651,
                              'char' => 22,
                            ),
                            'name' => 'rollback',
                            'call-type' => 3,
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 651,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 653,
                          'char' => 21,
                        ),
                        1 => 
                        array (
                          'type' => 'throw',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'exception',
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 653,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 654,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 655,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 655,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sql',
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 656,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 656,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 656,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                        'line' => 656,
                        'char' => 38,
                      ),
                      'name' => 'execute',
                      'call-type' => 3,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'queries',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 656,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                                'line' => 656,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 656,
                              'char' => 60,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ';',
                              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                              'line' => 656,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                            'line' => 656,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                          'line' => 656,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 656,
                      'char' => 65,
                    ),
                    'extra' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                      'line' => 656,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                    'line' => 656,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                  'line' => 657,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 659,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 659,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 660,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Modifies a table column based on a definition
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 625,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 625,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 624,
          'last-line' => 665,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'supportSequences',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 668,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 669,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the database system requires a sequence to produce
     * auto-numeric values
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 667,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 667,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 666,
          'last-line' => 674,
          'char' => 19,
        ),
        8 => 
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 677,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 678,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 676,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 676,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 675,
          'last-line' => 682,
          'char' => 19,
        ),
        9 => 
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 685,
                'char' => 18,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
              'line' => 686,
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
                'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
                'line' => 684,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
            'line' => 684,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
          'line' => 683,
          'last-line' => 687,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo/Postgresql.zep',
    'line' => 40,
    'char' => 5,
  ),
);