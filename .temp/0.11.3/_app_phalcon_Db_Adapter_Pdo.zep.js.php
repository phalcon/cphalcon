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
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Adapter',
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'name' => 'Phalcon\\Db\\Adapter',
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'name' => 'Phalcon\\Db\\Result\\Pdo',
        'alias' => 'ResultPdo',
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'name' => 'Phalcon\\Db\\ResultInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 17,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
        'line' => 18,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
    'line' => 37,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Db\\Adapter\\Pdo is the Phalcon\\Db that internally uses PDO to connect
 * to a database
 *
 * ```php
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
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
    'line' => 38,
    'char' => 8,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Pdo',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'Adapter',
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
          'name' => 'affectedRows',
          'docblock' => '**
     * Last affected rows
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
          'name' => 'pdo',
          'docblock' => '**
     * PDO Handler
     *
     * @var \\Pdo
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 55,
              'char' => 50,
            ),
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 57,
                  'char' => 14,
                ),
                'name' => 'connect',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'descriptor',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 57,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 57,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 57,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 59,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 59,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 59,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 59,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor for Phalcon\\Db\\Adapter\\Pdo
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 55,
          'last-line' => 73,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'affectedRows',
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 76,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'affectedRows',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 76,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 76,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of affected rows by the latest INSERT/UPDATE/DELETE
     * executed in the database system
     *
     *```php
     * $connection->execute(
     *     "DELETE FROM robots"
     * );
     *
     * echo $connection->affectedRows(), " were deleted";
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
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 75,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 74,
          'last-line' => 81,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'begin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 82,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 82,
              'char' => 46,
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
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 84,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 84,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 84,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'savepointName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 84,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 86,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 86,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 86,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 86,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 86,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 87,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 87,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 87,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 87,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 87,
                'char' => 33,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 88,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 89,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 94,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-incr',
                  'variable' => 'this',
                  'property' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 94,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
                  'variable' => 'transactionLevel',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 99,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'transactionLevel',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 99,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 99,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 99,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 99,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 101,
              'char' => 10,
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
                  'value' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 101,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 101,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 101,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'eventsManager',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ManagerInterface',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 105,
                          'char' => 71,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 105,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 105,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 105,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 105,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 105,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 106,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 106,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 106,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 106,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 106,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 107,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'db:beginTransaction',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 107,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 107,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 107,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 107,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 107,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 108,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 110,
                  'char' => 18,
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
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 110,
                      'char' => 24,
                    ),
                    'name' => 'beginTransaction',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 110,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 111,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 116,
              'char' => 10,
            ),
            6 => 
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
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 116,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 116,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nesting',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 116,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 116,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 116,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 116,
                      'char' => 51,
                    ),
                    'name' => 'isNestedTransactionsWithSavepoints',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 116,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 116,
                  'char' => 89,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 116,
                'char' => 89,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 117,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 120,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 120,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 120,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 120,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 120,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 120,
                  'char' => 67,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'savepointName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 121,
                      'char' => 34,
                    ),
                    'name' => 'getNestedTransactionSavepointName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 121,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 121,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 126,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 126,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 126,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 126,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 126,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 127,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'db:createSavepoint',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 127,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 127,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 127,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 127,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'savepointName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 127,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 127,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 127,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 128,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 130,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 130,
                  'char' => 21,
                ),
                'name' => 'createSavepoint',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'savepointName',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 130,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 130,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 130,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Starts a transaction in the connection
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 83,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 83,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 82,
          'last-line' => 135,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'commit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 136,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 136,
              'char' => 47,
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
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 138,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 138,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 138,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'savepointName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 138,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 140,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 140,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 140,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 140,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 140,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 141,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 141,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 141,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 141,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 141,
                'char' => 33,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 142,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 143,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 148,
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
                  'variable' => 'transactionLevel',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 148,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'transactionLevel',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 148,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 148,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 148,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 148,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 149,
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
                    'type' => 'variable',
                    'value' => 'transactionLevel',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 149,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 149,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 149,
                'char' => 39,
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
                          'value' => 'There is no active transaction',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 150,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 150,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 150,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 151,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 153,
              'char' => 10,
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
                  'value' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 153,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 153,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 153,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'eventsManager',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ManagerInterface',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 157,
                          'char' => 71,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 157,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 157,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 157,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 157,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 157,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 158,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 158,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 158,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 158,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 158,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 159,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'db:commitTransaction',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 159,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 159,
                            'char' => 57,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 159,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 159,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 159,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 160,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 165,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-decr',
                      'variable' => 'this',
                      'property' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 165,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 167,
                  'char' => 18,
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
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 167,
                      'char' => 24,
                    ),
                    'name' => 'commit',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 167,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 168,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 173,
              'char' => 10,
            ),
            6 => 
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
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 173,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 173,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nesting',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 173,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 173,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 173,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 173,
                      'char' => 51,
                    ),
                    'name' => 'isNestedTransactionsWithSavepoints',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 173,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 173,
                  'char' => 89,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 173,
                'char' => 89,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 177,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 177,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 177,
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
                          'assign-type' => 'object-property-decr',
                          'variable' => 'this',
                          'property' => 'transactionLevel',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 178,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 179,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 181,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 181,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 182,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 187,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 187,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 187,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 187,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 187,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 187,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 187,
                  'char' => 67,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'savepointName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 188,
                      'char' => 34,
                    ),
                    'name' => 'getNestedTransactionSavepointName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 188,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 188,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 190,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 190,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 190,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 190,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 190,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 191,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'db:releaseSavepoint',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 191,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 191,
                        'char' => 52,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 191,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 191,
                        'char' => 58,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'savepointName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 191,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 191,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 191,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 192,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 197,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-decr',
                  'variable' => 'this',
                  'property' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 197,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 199,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 199,
                  'char' => 21,
                ),
                'name' => 'releaseSavepoint',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'savepointName',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 199,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 199,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 199,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 200,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Commits the active transaction in the connection
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 137,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 137,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 136,
          'last-line' => 205,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'close',
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
                  'property' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 208,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 208,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 210,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 210,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Closes the active connection returning success. Phalcon automatically
     * closes and destroys active connections when the request ends
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 207,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 207,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 206,
          'last-line' => 236,
          'char' => 19,
        ),
        5 => 
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 237,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 237,
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
                  'variable' => 'username',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 239,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'password',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 239,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'dsnParts',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 239,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'dsnAttributes',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 239,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'dsnAttributesCustomRaw',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 239,
                  'char' => 80,
                ),
                5 => 
                array (
                  'variable' => 'dsnAttributesMap',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 240,
                  'char' => 29,
                ),
                6 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 240,
                  'char' => 38,
                ),
                7 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 240,
                  'char' => 43,
                ),
                8 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 240,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 242,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 242,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 242,
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
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 243,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'descriptor',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 243,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 243,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 243,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 243,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 247,
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
                  'value' => 'username',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 247,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 247,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'username',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 247,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 247,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 247,
                'char' => 49,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 248,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'username',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 248,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 248,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 252,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'password',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 252,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 252,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'password',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 252,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 252,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 252,
                'char' => 49,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 253,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'password',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 253,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 253,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 254,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 257,
              'char' => 10,
            ),
            4 => 
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 257,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'dialectClass',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 257,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 257,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 257,
                'char' => 43,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 258,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'dialectClass',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 258,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 258,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 259,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 265,
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 265,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 265,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 265,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 265,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 265,
                'char' => 47,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 266,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'options',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 266,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 266,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 267,
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
                      'variable' => 'options',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 268,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 268,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 269,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 272,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '\\Pdo',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 272,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ATTR_ERRMODE',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 272,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 272,
                      'char' => 39,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 272,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ERRMODE_EXCEPTION',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 272,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 272,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 272,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 274,
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
                  'variable' => 'dsnParts',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 274,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 274,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 278,
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
                  'value' => 'dsnAttributesCustomRaw',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 278,
                  'char' => 58,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'descriptor',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 278,
                    'char' => 52,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'dsn',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 278,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 278,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 278,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'dsnParts',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dsnAttributesCustomRaw',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 279,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 279,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 281,
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
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 281,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'dsn',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 281,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 281,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 282,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 289,
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
                  'variable' => 'dsnAttributesMap',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
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
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 290,
                            'char' => 18,
                          ),
                          'name' => 'getDsnDefaults',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 290,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 290,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'descriptor',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 292,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 292,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 292,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 292,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 294,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'dsnAttributesMap',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 294,
                'char' => 44,
              ),
              'key' => 'key',
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'dsnParts',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 295,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '=',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 295,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 295,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 295,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 295,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 295,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 296,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 299,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'dsnAttributes',
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
                          'value' => ';',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 299,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 299,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dsnParts',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 299,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 299,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 299,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 299,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 302,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => '\\Pdo',
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 303,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'type',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 303,
                                'char' => 24,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 303,
                              'char' => 24,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ':',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 303,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 303,
                            'char' => 28,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dsnAttributes',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 303,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 303,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 303,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'username',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 304,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 304,
                        'char' => 21,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'password',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 305,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 305,
                        'char' => 21,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 307,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 307,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 307,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 307,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 309,
              'char' => 14,
            ),
            13 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 309,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 310,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * This method is automatically called in \\Phalcon\\Db\\Adapter\\Pdo
     * constructor.
     *
     * Call it when you need to restore a database connection.
     *
     *```php
     * use Phalcon\\Db\\Adapter\\Pdo\\Mysql;
     *
     * // Make a connection
     * $connection = new Mysql(
     *     [
     *         "host"     => "localhost",
     *         "username" => "sigma",
     *         "password" => "secret",
     *         "dbname"   => "blog",
     *         "port"     => 3306,
     *     ]
     * );
     *
     * // Reconnect
     * $connection->connect();
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 238,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 238,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 237,
          'last-line' => 325,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'convertBoundParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sql',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 326,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 326,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 326,
              'char' => 70,
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
                  'variable' => 'boundSql',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'placeHolders',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'bindPattern',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 48,
                ),
                3 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'setOrder',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 67,
                ),
                5 => 
                array (
                  'variable' => 'placeMatch',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 328,
                  'char' => 79,
                ),
                6 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 329,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 331,
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
                  'variable' => 'placeHolders',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 331,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 331,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bindPattern',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '/\\\\?([0-9]+)|:([a-zA-Z0-9_]+):/',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 332,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 332,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 333,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 333,
                  'char' => 27,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'setOrder',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '2',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 334,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 334,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 336,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_match_all',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindPattern',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 336,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 336,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sql',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 336,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 336,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'matches',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 336,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 336,
                    'char' => 52,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'setOrder',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 336,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 336,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 336,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'matches',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 337,
                    'char' => 39,
                  ),
                  'value' => 'placeMatch',
                  'reverse' => 0,
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
                          'type' => 'fetch',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 338,
                            'char' => 56,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 338,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'placeMatch',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 338,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 338,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 338,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 338,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 338,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 338,
                        'char' => 56,
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
                                'type' => 'isset',
                                'left' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'placeMatch',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 339,
                                    'char' => 50,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 339,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 339,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 339,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 339,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 339,
                            'char' => 54,
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
                                      'value' => 'Matched parameter wasn\'t found in parameters list',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 342,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 342,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 342,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 343,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 345,
                          'char' => 22,
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
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 345,
                                  'char' => 69,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'params',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 345,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'placeMatch',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 345,
                                      'char' => 64,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '2',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 345,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 345,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 345,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 345,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 345,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 345,
                            'char' => 69,
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
                                      'value' => 'Matched parameter wasn\'t found in parameters list',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 348,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 348,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 348,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 349,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 350,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 352,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'placeHolders',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 352,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 352,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 353,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 355,
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
                      'variable' => 'boundSql',
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
                              'type' => 'variable',
                              'value' => 'bindPattern',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 355,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 355,
                            'char' => 52,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '?',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 355,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 355,
                            'char' => 55,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sql',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 355,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 355,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 355,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 355,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 356,
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
                      'variable' => 'boundSql',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'sql',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 357,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 357,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 358,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 360,
              'char' => 14,
            ),
            3 => 
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
                      'value' => 'sql',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 361,
                      'char' => 20,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundSql',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 361,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 361,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'params',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 362,
                      'char' => 20,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeHolders',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 363,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 363,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 363,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 364,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts bound parameters such as :name: or ?1 into PDO bind params ?
     *
     *```php
     * print_r(
     *     $connection->convertBoundParams(
     *         "SELECT * FROM robots WHERE name = :name:",
     *         [
     *             "Bender",
     *         ]
     *     )
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
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 327,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 326,
          'last-line' => 373,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeString',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'str',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 374,
              'char' => 44,
            ),
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 376,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 376,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 376,
                  'char' => 26,
                ),
                'name' => 'quote',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'str',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 376,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 376,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 376,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 377,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escapes a value to avoid SQL injections according to the active charset
     * in the connection
     *
     *```php
     * $escapedStr = $connection->escapeString("some dangerous value");
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 375,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 375,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 374,
          'last-line' => 398,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'execute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 399,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 399,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 399,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 399,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 399,
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
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 401,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'affectedRows',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 401,
                  'char' => 40,
                ),
                2 => 
                array (
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 401,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'newStatement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 401,
                  'char' => 59,
                ),
                4 => 
                array (
                  'variable' => 'statement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 401,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 406,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 406,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 406,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 406,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 406,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 406,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 406,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 407,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 407,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 407,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 407,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 407,
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
                      'property' => 'sqlStatement',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'sqlStatement',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 408,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 408,
                      'char' => 50,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sqlVariables',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 409,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 409,
                      'char' => 48,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sqlBindTypes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 410,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 410,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 412,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 412,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'db:beforeQuery',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 412,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 412,
                          'char' => 50,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 412,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 412,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 412,
                      'char' => 60,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 412,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 412,
                    'char' => 68,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 413,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 414,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 415,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
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
                  'variable' => 'affectedRows',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 420,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 420,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 422,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 422,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 422,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pdo',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 422,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 422,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 422,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 422,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 424,
              'char' => 10,
            ),
            5 => 
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
                    'value' => 'bindParams',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 424,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 424,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 424,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 424,
                'char' => 39,
              ),
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
                      'variable' => 'statement',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pdo',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 425,
                          'char' => 33,
                        ),
                        'name' => 'prepare',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sqlStatement',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 425,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 425,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 425,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 425,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 427,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'statement',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 427,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 427,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 427,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 427,
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
                          'variable' => 'newStatement',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 428,
                              'char' => 41,
                            ),
                            'name' => 'executePrepared',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'statement',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 429,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 429,
                                'char' => 30,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'bindParams',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 430,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 430,
                                'char' => 31,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'bindTypes',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 432,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 432,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 432,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 432,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 434,
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
                          'variable' => 'affectedRows',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'newStatement',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 434,
                              'char' => 49,
                            ),
                            'name' => 'rowCount',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 434,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 434,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 435,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 436,
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
                      'variable' => 'affectedRows',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pdo',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 437,
                          'char' => 36,
                        ),
                        'name' => 'exec',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sqlStatement',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 437,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 437,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 437,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 437,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 438,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 443,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'affectedRows',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 443,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 443,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'integer',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 443,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 443,
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
                      'property' => 'affectedRows',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'affectedRows',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 444,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 444,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 446,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 446,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 446,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 446,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 446,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 447,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'db:afterQuery',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 447,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 447,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 447,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 447,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 447,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 448,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 449,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 451,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 451,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 452,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server doesn\'t
     * return any rows
     *
     *```php
     * // Inserting data
     * $success = $connection->execute(
     *     "INSERT INTO robots VALUES (1, \'Astro Boy\')"
     * );
     *
     * $success = $connection->execute(
     *     "INSERT INTO robots VALUES (?, ?)",
     *     [
     *         1,
     *         "Astro Boy",
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 400,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 400,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 399,
          'last-line' => 475,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'executePrepared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'statement',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\PDOStatement',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 476,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 476,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 476,
              'char' => 83,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 476,
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
                  'variable' => 'wildcard',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'castValue',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'parameter',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 66,
                ),
                6 => 
                array (
                  'variable' => 'itemValue',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 478,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 480,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'placeholders',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 480,
                'char' => 45,
              ),
              'key' => 'wildcard',
              'value' => 'value',
              'reverse' => 0,
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
                        'value' => 'wildcard',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 481,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 481,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'integer',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 481,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 481,
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
                          'variable' => 'parameter',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'wildcard',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 482,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 482,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 482,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 482,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 483,
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
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'wildcard',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 483,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 483,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 483,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 483,
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
                              'variable' => 'parameter',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'wildcard',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 484,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 484,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 485,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 485,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
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
                              'value' => 'Invalid bind parameter (1)',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 486,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 486,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 486,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 487,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 489,
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
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dataTypes',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 489,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 489,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 489,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 489,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'fetch',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 489,
                        'char' => 77,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dataTypes',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 489,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'wildcard',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 489,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 489,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 489,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 489,
                    'char' => 77,
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
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 494,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 494,
                            'char' => 55,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'BIND_PARAM_DECIMAL',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 494,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 494,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 494,
                        'char' => 55,
                      ),
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
                              'variable' => 'castValue',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'string',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 495,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 495,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 495,
                              'char' => 51,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'type',
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 496,
                                  'char' => 49,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_SKIP',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 496,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 496,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 496,
                              'char' => 49,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 497,
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
                            'type' => 'fcall',
                            'name' => 'globals_get',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'db.force_casting',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 498,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 498,
                                'char' => 52,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 498,
                            'char' => 54,
                          ),
                          'statements' => 
                          array (
                            0 => 
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
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 499,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 499,
                                  'char' => 42,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 499,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 499,
                                'char' => 50,
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
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 500,
                                    'char' => 41,
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
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 502,
                                          'char' => 60,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'BIND_PARAM_INT',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 502,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 502,
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
                                              'assign-type' => 'variable',
                                              'operator' => 'assign',
                                              'variable' => 'castValue',
                                              'expr' => 
                                              array (
                                                'type' => 'fcall',
                                                'name' => 'intval',
                                                'call-type' => 1,
                                                'parameters' => 
                                                array (
                                                  0 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'value',
                                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                      'line' => 503,
                                                      'char' => 65,
                                                    ),
                                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                    'line' => 503,
                                                    'char' => 65,
                                                  ),
                                                  1 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'int',
                                                      'value' => '10',
                                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                      'line' => 503,
                                                      'char' => 69,
                                                    ),
                                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                    'line' => 503,
                                                    'char' => 69,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                'line' => 503,
                                                'char' => 70,
                                              ),
                                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                              'line' => 503,
                                              'char' => 70,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 504,
                                          'char' => 41,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'break',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 506,
                                          'char' => 36,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 506,
                                      'char' => 36,
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
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 506,
                                          'char' => 60,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'BIND_PARAM_STR',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 506,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 506,
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
                                              'assign-type' => 'variable',
                                              'operator' => 'assign',
                                              'variable' => 'castValue',
                                              'expr' => 
                                              array (
                                                'type' => 'cast',
                                                'left' => 'string',
                                                'right' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'value',
                                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                  'line' => 507,
                                                  'char' => 67,
                                                ),
                                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                'line' => 507,
                                                'char' => 67,
                                              ),
                                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                              'line' => 507,
                                              'char' => 67,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 508,
                                          'char' => 41,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'break',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 510,
                                          'char' => 36,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 510,
                                      'char' => 36,
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
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 510,
                                          'char' => 61,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'BIND_PARAM_NULL',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 510,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 510,
                                        'char' => 61,
                                      ),
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
                                              'variable' => 'castValue',
                                              'expr' => 
                                              array (
                                                'type' => 'null',
                                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                'line' => 511,
                                                'char' => 57,
                                              ),
                                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                              'line' => 511,
                                              'char' => 57,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 512,
                                          'char' => 41,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'break',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 514,
                                          'char' => 36,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 514,
                                      'char' => 36,
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
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 514,
                                          'char' => 61,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'BIND_PARAM_BOOL',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 514,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 514,
                                        'char' => 61,
                                      ),
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
                                              'variable' => 'castValue',
                                              'expr' => 
                                              array (
                                                'type' => 'cast',
                                                'left' => 'bool',
                                                'right' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'value',
                                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                  'line' => 515,
                                                  'char' => 65,
                                                ),
                                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                'line' => 515,
                                                'char' => 65,
                                              ),
                                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                              'line' => 515,
                                              'char' => 65,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 516,
                                          'char' => 41,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'break',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 518,
                                          'char' => 39,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 518,
                                      'char' => 39,
                                    ),
                                    4 => 
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
                                              'assign-type' => 'variable',
                                              'operator' => 'assign',
                                              'variable' => 'castValue',
                                              'expr' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'value',
                                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                                'line' => 519,
                                                'char' => 58,
                                              ),
                                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                              'line' => 519,
                                              'char' => 58,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 520,
                                          'char' => 41,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'break',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 521,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 521,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 522,
                                  'char' => 25,
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
                                      'variable' => 'castValue',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 523,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 523,
                                      'char' => 50,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 524,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 525,
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
                                  'variable' => 'castValue',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 526,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 526,
                                  'char' => 46,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 527,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 528,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 533,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'castValue',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 533,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 533,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 533,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 533,
                        'char' => 46,
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
                              'type' => 'variable',
                              'value' => 'type',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 534,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'static-constant-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Column',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 534,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'BIND_SKIP',
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 534,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 534,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 534,
                            'char' => 50,
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
                                  'value' => 'statement',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 535,
                                  'char' => 35,
                                ),
                                'name' => 'bindValue',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameter',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 535,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 535,
                                    'char' => 55,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'castValue',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 535,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 535,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 535,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 536,
                              'char' => 21,
                            ),
                          ),
                          'else_statements' => 
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
                                  'value' => 'statement',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 537,
                                  'char' => 35,
                                ),
                                'name' => 'bindValue',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameter',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 537,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 537,
                                    'char' => 55,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'castValue',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 537,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 537,
                                    'char' => 66,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'type',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 537,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 537,
                                    'char' => 72,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 537,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 538,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 539,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'castValue',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 540,
                            'char' => 58,
                          ),
                          'key' => 'position',
                          'value' => 'itemValue',
                          'reverse' => 0,
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
                                  'type' => 'variable',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 541,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'Column',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 541,
                                    'char' => 54,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'BIND_SKIP',
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 541,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 541,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 541,
                                'char' => 54,
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
                                      'value' => 'statement',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 542,
                                      'char' => 39,
                                    ),
                                    'name' => 'bindValue',
                                    'call-type' => 1,
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
                                            'value' => 'parameter',
                                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                            'line' => 543,
                                            'char' => 43,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'position',
                                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                            'line' => 543,
                                            'char' => 53,
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 543,
                                          'char' => 53,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 543,
                                        'char' => 53,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'itemValue',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 545,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 545,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 545,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 546,
                                  'char' => 25,
                                ),
                              ),
                              'else_statements' => 
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
                                      'value' => 'statement',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 547,
                                      'char' => 39,
                                    ),
                                    'name' => 'bindValue',
                                    'call-type' => 1,
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
                                            'value' => 'parameter',
                                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                            'line' => 548,
                                            'char' => 43,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'position',
                                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                            'line' => 548,
                                            'char' => 53,
                                          ),
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 548,
                                          'char' => 53,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 548,
                                        'char' => 53,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'itemValue',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 549,
                                          'char' => 42,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 549,
                                        'char' => 42,
                                      ),
                                      2 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'type',
                                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                          'line' => 551,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 551,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 551,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 552,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 553,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 554,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 555,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
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
                            'value' => 'value',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 556,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 556,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 556,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 556,
                        'char' => 42,
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
                              'value' => 'statement',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 557,
                              'char' => 31,
                            ),
                            'name' => 'bindValue',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameter',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 557,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 557,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 557,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 557,
                                'char' => 58,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 557,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 558,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 559,
                            'char' => 54,
                          ),
                          'key' => 'position',
                          'value' => 'itemValue',
                          'reverse' => 0,
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
                                  'value' => 'statement',
                                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                  'line' => 560,
                                  'char' => 35,
                                ),
                                'name' => 'bindValue',
                                'call-type' => 1,
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
                                        'value' => 'parameter',
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 560,
                                        'char' => 56,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'position',
                                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                        'line' => 560,
                                        'char' => 66,
                                      ),
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 560,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 560,
                                    'char' => 66,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'itemValue',
                                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                      'line' => 560,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                    'line' => 560,
                                    'char' => 77,
                                  ),
                                ),
                                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                                'line' => 560,
                                'char' => 78,
                              ),
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 561,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 562,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 563,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 564,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 566,
              'char' => 17,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'statement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 566,
                  'char' => 19,
                ),
                'name' => 'execute',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 566,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 567,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'statement',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 567,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 568,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Executes a prepared statement binding. This function uses integer indexes
     * starting from zero
     *
     *```php
     * use Phalcon\\Db\\Column;
     *
     * $statement = $db->prepare(
     *     "SELECT * FROM robots WHERE name = :name"
     * );
     *
     * $result = $connection->executePrepared(
     *     $statement,
     *     [
     *         "name" => "Voltron",
     *     ],
     *     [
     *         "name" => Column::BIND_PARAM_INT,
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
                  'value' => '\\PDOStatement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 477,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 477,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 477,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 476,
          'last-line' => 572,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getErrorInfo',
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 575,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 575,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 575,
                  'char' => 26,
                ),
                'name' => 'errorInfo',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 575,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 576,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the error info, if any
     *',
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 573,
          'last-line' => 580,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInternalHandler',
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 583,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 583,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 583,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 584,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return internal PDO handler
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
                  'value' => '\\Pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 582,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 582,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 582,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 581,
          'last-line' => 588,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTransactionLevel',
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
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 591,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 591,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 591,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 592,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current transaction nesting level
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 590,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 590,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 589,
          'last-line' => 605,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUnderTransaction',
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
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 608,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 610,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 610,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 610,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 610,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 610,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 612,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 612,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 612,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 612,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 612,
                'char' => 33,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 613,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 614,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 616,
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
                  'value' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 616,
                  'char' => 20,
                ),
                'name' => 'inTransaction',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 616,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 617,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether the connection is under a transaction
     *
     *```php
     * $connection->begin();
     *
     * // true
     * var_dump(
     *     $connection->isUnderTransaction()
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 607,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 607,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 606,
          'last-line' => 640,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'lastInsertId',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sequenceName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 641,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 641,
              'char' => 53,
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
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 643,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 645,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 645,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 645,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 645,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 645,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 647,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 647,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 647,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 647,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 647,
                'char' => 33,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 648,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 649,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 651,
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
                  'value' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 651,
                  'char' => 20,
                ),
                'name' => 'lastInsertId',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sequenceName',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 651,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 651,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 651,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 652,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the insert id for the auto_increment/serial column inserted in
     * the latest executed SQL statement
     *
     *```php
     * // Inserting a new robot
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         "Astro Boy",
     *         1952,
     *     ],
     *     [
     *         "name",
     *         "year",
     *     ]
     * );
     *
     * // Getting the generated id
     * $id = $connection->lastInsertId();
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
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 641,
                'char' => 62,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 642,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 642,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 641,
          'last-line' => 674,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'prepare',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 675,
              'char' => 49,
            ),
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 677,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 677,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 677,
                  'char' => 26,
                ),
                'name' => 'prepare',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sqlStatement',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 677,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 677,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 677,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 678,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a PDO prepared statement to be executed with \'executePrepared\'
     *
     *```php
     * use Phalcon\\Db\\Column;
     *
     * $statement = $db->prepare(
     *     "SELECT * FROM robots WHERE name = :name"
     * );
     *
     * $result = $connection->executePrepared(
     *     $statement,
     *     [
     *         "name" => "Voltron",
     *     ],
     *     [
     *         "name" => Column::BIND_PARAM_INT,
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
                  'value' => '\\PDOStatement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 676,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 676,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 676,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 675,
          'last-line' => 698,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 699,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 699,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 699,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 699,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 699,
              'char' => 92,
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
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 701,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 701,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'statement',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 701,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 701,
                  'char' => 50,
                ),
                4 => 
                array (
                  'variable' => 'types',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 701,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 703,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 703,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 703,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 703,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 703,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 703,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 703,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 708,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 708,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 708,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 708,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 708,
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
                      'property' => 'sqlStatement',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'sqlStatement',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 709,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 709,
                      'char' => 50,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sqlVariables',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 710,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 710,
                      'char' => 48,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sqlBindTypes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 711,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 711,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 713,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 713,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'db:beforeQuery',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 713,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 713,
                          'char' => 50,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 713,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 713,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 713,
                      'char' => 60,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 713,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 713,
                    'char' => 68,
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
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 714,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 715,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 716,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 718,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 718,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 718,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pdo',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 718,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 718,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 718,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 718,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 719,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'bindParams',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 719,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 719,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 719,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 719,
                'char' => 39,
              ),
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 720,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 720,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 721,
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
                      'variable' => 'types',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 721,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 721,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 722,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 723,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 723,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 724,
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
                      'variable' => 'types',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 724,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 724,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 725,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 727,
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
                  'variable' => 'statement',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 727,
                      'char' => 29,
                    ),
                    'name' => 'prepare',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sqlStatement',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 727,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 727,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 727,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 727,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 728,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'statement',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 728,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 728,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 728,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 728,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 728,
                'char' => 48,
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
                          'value' => 'Cannot prepare statement',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 729,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 729,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 729,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 730,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 732,
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
                  'variable' => 'statement',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 732,
                      'char' => 30,
                    ),
                    'name' => 'executePrepared',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'statement',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 732,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 732,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 732,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 732,
                        'char' => 64,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'types',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 732,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 732,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 732,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 732,
                  'char' => 72,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 737,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'statement',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 737,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 737,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 737,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 737,
                'char' => 39,
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 738,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 738,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 738,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 738,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 739,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'db:afterQuery',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 739,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 739,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 739,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 739,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 739,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 740,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 742,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'ResultPdo',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 743,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 743,
                        'char' => 21,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'statement',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 744,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 744,
                        'char' => 26,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sqlStatement',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 745,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 745,
                        'char' => 29,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 746,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 746,
                        'char' => 27,
                      ),
                      4 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindTypes',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 748,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 748,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 748,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 749,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 751,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'statement',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 751,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 752,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server is
     * returning rows
     *
     *```php
     * // Querying data
     * $resultset = $connection->query(
     *     "SELECT * FROM robots WHERE type = \'mechanical\'"
     * );
     *
     * $resultset = $connection->query(
     *     "SELECT * FROM robots WHERE type = ?",
     *     [
     *         "mechanical",
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
                  'value' => 'ResultInterface',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 699,
                  'char' => 115,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 699,
                'char' => 115,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 700,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 700,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 699,
          'last-line' => 756,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 757,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 757,
              'char' => 49,
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
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 759,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 759,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 759,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'savepointName',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 759,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 761,
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
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 761,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 761,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 761,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 761,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 762,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'pdo',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 762,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 762,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 762,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 762,
                'char' => 33,
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
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 763,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 764,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 769,
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
                  'variable' => 'transactionLevel',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 769,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'transactionLevel',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 769,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 769,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 769,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 769,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 770,
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
                    'type' => 'variable',
                    'value' => 'transactionLevel',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 770,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 770,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 770,
                'char' => 39,
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
                          'value' => 'There is no active transaction',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 771,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 771,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 771,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 772,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 774,
              'char' => 10,
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
                  'value' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 774,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 774,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 774,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'eventsManager',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ManagerInterface',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 778,
                          'char' => 71,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 778,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 778,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 778,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 778,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 778,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 779,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 779,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 779,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 779,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 779,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 780,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'db:rollbackTransaction',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 780,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 780,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                              'line' => 780,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                            'line' => 780,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 780,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 781,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 786,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-decr',
                      'variable' => 'this',
                      'property' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 786,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 788,
                  'char' => 18,
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
                      'value' => 'pdo',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 788,
                      'char' => 24,
                    ),
                    'name' => 'rollback',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 788,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 789,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 794,
              'char' => 10,
            ),
            6 => 
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
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 794,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 794,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nesting',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 794,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 794,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 794,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 794,
                      'char' => 51,
                    ),
                    'name' => 'isNestedTransactionsWithSavepoints',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 794,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 794,
                  'char' => 89,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 794,
                'char' => 89,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactionLevel',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 798,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 798,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 798,
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
                          'assign-type' => 'object-property-decr',
                          'variable' => 'this',
                          'property' => 'transactionLevel',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 799,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 800,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 802,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 802,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 803,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 805,
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
                  'variable' => 'savepointName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 805,
                      'char' => 34,
                    ),
                    'name' => 'getNestedTransactionSavepointName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 805,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 805,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 810,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 810,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 810,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 810,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 810,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 810,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 810,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 811,
              'char' => 10,
            ),
            9 => 
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 811,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 811,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 811,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 811,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 812,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'db:rollbackSavepoint',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 812,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 812,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 812,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 812,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'savepointName',
                          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                          'line' => 812,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                        'line' => 812,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 812,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 813,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 818,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-decr',
                  'variable' => 'this',
                  'property' => 'transactionLevel',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 818,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 820,
              'char' => 14,
            ),
            11 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                  'line' => 820,
                  'char' => 21,
                ),
                'name' => 'rollbackSavepoint',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'savepointName',
                      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                      'line' => 820,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                    'line' => 820,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 820,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
              'line' => 821,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rollbacks the active transaction in the connection
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 758,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 758,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 757,
          'last-line' => 825,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getDsnDefaults',
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
                'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
                'line' => 826,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
            'line' => 826,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
          'line' => 826,
          'last-line' => 827,
          'char' => 31,
        ),
      ),
      'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
      'line' => 38,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Db/Adapter/Pdo.zep',
    'line' => 38,
    'char' => 14,
  ),
);