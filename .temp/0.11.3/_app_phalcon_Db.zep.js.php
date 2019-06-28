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
    'file' => '/app/phalcon/Db.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Db.zep',
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
        'name' => '\\PDO',
        'alias' => 'Pdo',
        'file' => '/app/phalcon/Db.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Db.zep',
    'line' => 57,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Db and its related classes provide a simple SQL database interface
 * for Phalcon Framework. The Phalcon\\Db is the basic class you use to connect
 * your PHP application to an RDBMS. There is a different adapter class for each
 * brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to
 * interact with databases using higher level of abstraction use
 * Phalcon\\Mvc\\Model.
 *
 * Phalcon\\Db is an abstract class. You only can use it with a database adapter
 * like Phalcon\\Db\\Adapter\\Pdo
 *
 *```php
 * use Phalcon\\Db;
 * use Phalcon\\Db\\Exception;
 * use Phalcon\\Db\\Adapter\\Pdo\\Mysql as MysqlConnection;
 *
 * try {
 *     $connection = new MysqlConnection(
 *         [
 *             "host"     => "192.168.0.11",
 *             "username" => "sigma",
 *             "password" => "secret",
 *             "dbname"   => "blog",
 *             "port"     => "3306",
 *         ]
 *     );
 *
 *     $result = $connection->query(
 *         "SELECT * FROM robots LIMIT 5"
 *     );
 *
 *     $result->setFetchMode(Db::FETCH_NUM);
 *
 *     while ($robot = $result->fetch()) {
 *         print_r($robot);
 *     }
 * } catch (Exception $e) {
 *     echo $e->getMessage(), PHP_EOL;
 * }
 * ```
 *',
    'file' => '/app/phalcon/Db.zep',
    'line' => 58,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Db',
    'abstract' => 1,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setup',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db.zep',
              'line' => 81,
              'char' => 48,
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
                  'variable' => 'escapeIdentifiers',
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 83,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'forceCasting',
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 83,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Db.zep',
              'line' => 88,
              'char' => 10,
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
                  'value' => 'escapeIdentifiers',
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 88,
                  'char' => 67,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 88,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'escapeSqlIdentifiers',
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 88,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 88,
                  'char' => 67,
                ),
                'file' => '/app/phalcon/Db.zep',
                'line' => 88,
                'char' => 67,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'globals_set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'db.escape_identifiers',
                          'file' => '/app/phalcon/Db.zep',
                          'line' => 89,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Db.zep',
                        'line' => 89,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'escapeIdentifiers',
                          'file' => '/app/phalcon/Db.zep',
                          'line' => 89,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Db.zep',
                        'line' => 89,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 89,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db.zep',
              'line' => 95,
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
                  'value' => 'forceCasting',
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 95,
                  'char' => 54,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 95,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'forceCasting',
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 95,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 95,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Db.zep',
                'line' => 95,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'globals_set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'db.force_casting',
                          'file' => '/app/phalcon/Db.zep',
                          'line' => 96,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Db.zep',
                        'line' => 96,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'forceCasting',
                          'file' => '/app/phalcon/Db.zep',
                          'line' => 96,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Db.zep',
                        'line' => 96,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Db.zep',
                    'line' => 96,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Db.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db.zep',
              'line' => 98,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Enables/disables options in the Database component
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 81,
          'last-line' => 99,
          'char' => 26,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_ASSOC',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 60,
              'char' => 47,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_ASSOC',
              'file' => '/app/phalcon/Db.zep',
              'line' => 60,
              'char' => 47,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 60,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 61,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_BOTH',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 61,
              'char' => 46,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_BOTH',
              'file' => '/app/phalcon/Db.zep',
              'line' => 61,
              'char' => 46,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 61,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 62,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_BOUND',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 62,
              'char' => 47,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_BOUND',
              'file' => '/app/phalcon/Db.zep',
              'line' => 62,
              'char' => 47,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 62,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 63,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_CLASS',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 63,
              'char' => 47,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_CLASS',
              'file' => '/app/phalcon/Db.zep',
              'line' => 63,
              'char' => 47,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 63,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 64,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_CLASSTYPE',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 64,
              'char' => 51,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_CLASSTYPE',
              'file' => '/app/phalcon/Db.zep',
              'line' => 64,
              'char' => 51,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 64,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 65,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_COLUMN',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 65,
              'char' => 48,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_COLUMN',
              'file' => '/app/phalcon/Db.zep',
              'line' => 65,
              'char' => 48,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 65,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 66,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_FUNC',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 66,
              'char' => 46,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_FUNC',
              'file' => '/app/phalcon/Db.zep',
              'line' => 66,
              'char' => 46,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 66,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 67,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_GROUP',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 67,
              'char' => 47,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_GROUP',
              'file' => '/app/phalcon/Db.zep',
              'line' => 67,
              'char' => 47,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 67,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 68,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_INTO',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 68,
              'char' => 46,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_INTO',
              'file' => '/app/phalcon/Db.zep',
              'line' => 68,
              'char' => 46,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 68,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 69,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_KEY_PAIR',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 69,
              'char' => 50,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_KEY_PAIR',
              'file' => '/app/phalcon/Db.zep',
              'line' => 69,
              'char' => 50,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 69,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 70,
          'char' => 9,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_LAZY',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 70,
              'char' => 46,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_LAZY',
              'file' => '/app/phalcon/Db.zep',
              'line' => 70,
              'char' => 46,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 70,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 71,
          'char' => 9,
        ),
        11 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_NAMED',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 71,
              'char' => 47,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_NAMED',
              'file' => '/app/phalcon/Db.zep',
              'line' => 71,
              'char' => 47,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 71,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 72,
          'char' => 9,
        ),
        12 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_NUM',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 72,
              'char' => 45,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_NUM',
              'file' => '/app/phalcon/Db.zep',
              'line' => 72,
              'char' => 45,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 72,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 73,
          'char' => 9,
        ),
        13 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_OBJ',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 73,
              'char' => 45,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_OBJ',
              'file' => '/app/phalcon/Db.zep',
              'line' => 73,
              'char' => 45,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 73,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 74,
          'char' => 9,
        ),
        14 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_PROPS_LATE',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 74,
              'char' => 52,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_PROPS_LATE',
              'file' => '/app/phalcon/Db.zep',
              'line' => 74,
              'char' => 52,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 74,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 75,
          'char' => 9,
        ),
        15 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_SERIALIZE',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 75,
              'char' => 51,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_SERIALIZE',
              'file' => '/app/phalcon/Db.zep',
              'line' => 75,
              'char' => 51,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 75,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 76,
          'char' => 9,
        ),
        16 => 
        array (
          'type' => 'const',
          'name' => 'FETCH_UNIQUE',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => '\\Pdo',
              'file' => '/app/phalcon/Db.zep',
              'line' => 76,
              'char' => 48,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_UNIQUE',
              'file' => '/app/phalcon/Db.zep',
              'line' => 76,
              'char' => 48,
            ),
            'file' => '/app/phalcon/Db.zep',
            'line' => 76,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Db.zep',
          'line' => 80,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Db.zep',
      'line' => 58,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Db.zep',
    'line' => 58,
    'char' => 14,
  ),
);