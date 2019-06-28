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
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db\\Result',
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
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
        'file' => '/app/phalcon/Db/Result/Pdo.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
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
        'name' => 'Phalcon\\Db\\ResultInterface',
        'file' => '/app/phalcon/Db/Result/Pdo.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
    'line' => 17,
    'char' => 36,
  ),
  4 => 
  array (
    'type' => 'cblock',
    'value' => '
#include <ext/pdo/php_pdo_driver.h>
',
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
    'line' => 33,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Encapsulates the resultset internals
 *
 * ```php
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \\Phalcon\\Db::FETCH_NUM
 * );
 *
 * while ($robot = $result->fetchArray()) {
 *     print_r($robot);
 * }
 * ```
 *',
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
    'line' => 34,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Pdo',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ResultInterface',
        'file' => '/app/phalcon/Db/Result/Pdo.zep',
        'line' => 35,
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
          'name' => 'bindParams',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 38,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'bindTypes',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 40,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'connection',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 44,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'fetchMode',
          'default' => 
          array (
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => 'Db',
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 45,
              'char' => 40,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'FETCH_OBJ',
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 45,
              'char' => 40,
            ),
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 45,
            'char' => 40,
          ),
          'docblock' => '**
     * Active fetch mode
     *',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 51,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'pdoStatement',
          'docblock' => '**
     * Internal resultset
     *
     * @var \\PDOStatement
     *',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 54,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'result',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 56,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'rowCount',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 56,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 58,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sqlStatement',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 62,
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
              'name' => 'connection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Db\\AdapterInterface',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 63,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 63,
              'char' => 65,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'result',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\PDOStatement',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 63,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 63,
              'char' => 89,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 64,
                'char' => 28,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 64,
              'char' => 28,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 64,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 64,
              'char' => 47,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 64,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 64,
              'char' => 65,
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
                  'property' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 66,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 66,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'pdoStatement',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'result',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 67,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 67,
                  'char' => 40,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'sqlStatement',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sqlStatement',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 68,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 68,
                  'char' => 46,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'bindParams',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 69,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 69,
                  'char' => 42,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'bindTypes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'bindTypes',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 70,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 70,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Db\\Result\\Pdo constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 63,
          'last-line' => 88,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dataSeek',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'number',
              'const' => 0,
              'data-type' => 'long',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 89,
              'char' => 41,
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
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 91,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'pdo',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 91,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'sqlStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 91,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 91,
                  'char' => 54,
                ),
                4 => 
                array (
                  'variable' => 'statement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 91,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 92,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'long',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'n',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 92,
                  'char' => 15,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 94,
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
                  'variable' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 94,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 94,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 94,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 94,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'pdo',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 95,
                      'char' => 30,
                    ),
                    'name' => 'getInternalHandler',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 95,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 95,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'sqlStatement',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 96,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sqlStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 96,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 96,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 96,
                  'char' => 46,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 97,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 97,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 97,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 97,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 103,
              'char' => 10,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 103,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 103,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 103,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 103,
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
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 104,
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
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 104,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 104,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 104,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 104,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
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
                        'value' => 'statement',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 106,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 106,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 106,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 106,
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
                          'variable' => 'statement',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'connection',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 107,
                              'char' => 44,
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
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 108,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 108,
                                'char' => 30,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'bindParams',
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 109,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 109,
                                'char' => 31,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                    'line' => 110,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'bindTypes',
                                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                    'line' => 111,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 111,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 111,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 111,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 111,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 112,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 113,
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
                      'variable' => 'statement',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pdo',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 114,
                          'char' => 33,
                        ),
                        'name' => 'query',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sqlStatement',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 114,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 114,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 114,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 114,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 117,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'pdoStatement',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'statement',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 117,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 117,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 119,
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
                  'variable' => 'n',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '-1',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 119,
                    'char' => 19,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 119,
                  'char' => 19,
                ),
                1 => 
                array (
                  'assign-type' => 'decr',
                  'variable' => 'number',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 120,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 122,
              'char' => 13,
            ),
            6 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'n',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 122,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'number',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 122,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 122,
                'char' => 27,
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
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 123,
                      'char' => 23,
                    ),
                    'name' => 'fetch',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 123,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 125,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'n',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 125,
                      'char' => 20,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 126,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Moves internal resultset cursor to another position letting us to fetch a
     * certain row
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * // Move to third row on result
     * $result->dataSeek(2);
     *
     * // Fetch third row
     * $row = $result->fetch();
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 89,
          'last-line' => 133,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'execute',
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
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 136,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdoStatement',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 136,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 136,
                  'char' => 35,
                ),
                'name' => 'execute',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 136,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Allows to execute the statement again. Some database systems don\'t
     * support scrollable cursors. So, as cursors are forward only, we need to
     * execute the cursor again to fetch rows from the begining
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
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 134,
          'last-line' => 155,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetch',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchStyle',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 156,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 156,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'cursorOrientation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 156,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 156,
              'char' => 78,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'cursorOffset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 156,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 156,
              'char' => 103,
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
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 158,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdoStatement',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 158,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 158,
                  'char' => 35,
                ),
                'name' => 'fetch',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fetchStyle',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 159,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 159,
                    'char' => 23,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cursorOrientation',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 160,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 160,
                    'char' => 30,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cursorOffset',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 162,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 162,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 162,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 163,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Fetches an array/object of strings that corresponds to the fetched row,
     * or FALSE if there are no more rows. This method is affected by the active
     * fetch flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM robots ORDER BY name");
     *
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_OBJ
     * );
     *
     * while ($robot = $result->fetch()) {
     *     echo $robot->name;
     * }
     *```
     *',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 156,
          'last-line' => 177,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchAll',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchStyle',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 178,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 178,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchArgument',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 178,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 178,
              'char' => 77,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ctorArgs',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 178,
                'char' => 98,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 178,
              'char' => 98,
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
                  'variable' => 'pdoStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 180,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 182,
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
                  'variable' => 'pdoStatement',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 182,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdoStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 182,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 182,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 182,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 184,
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
                    'value' => 'fetchStyle',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 184,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 184,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'integer',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 184,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 184,
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
                      'value' => 'pdoStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 185,
                      'char' => 33,
                    ),
                    'name' => 'fetchAll',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 185,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 186,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 188,
              'char' => 10,
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
                  'value' => 'fetchStyle',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 188,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Db',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 188,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'FETCH_CLASS',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 188,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 188,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 188,
                'char' => 42,
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
                      'value' => 'pdoStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 189,
                      'char' => 33,
                    ),
                    'name' => 'fetchAll',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fetchStyle',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 190,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 190,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fetchArgument',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 191,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 191,
                        'char' => 30,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ctorArgs',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 193,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 193,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 193,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 194,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 196,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fetchStyle',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 196,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Db',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 196,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'FETCH_COLUMN',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 196,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 196,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 196,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fetchStyle',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 196,
                    'char' => 58,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Db',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 196,
                      'char' => 75,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'FETCH_FUNC',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 196,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 196,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 196,
                  'char' => 75,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 196,
                'char' => 75,
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
                      'value' => 'pdoStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 197,
                      'char' => 33,
                    ),
                    'name' => 'fetchAll',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fetchStyle',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 197,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 197,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fetchArgument',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 197,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 197,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 197,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 198,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 200,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'pdoStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 200,
                  'char' => 29,
                ),
                'name' => 'fetchAll',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fetchStyle',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 200,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 200,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 200,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 201,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of arrays containing all the records in the result
     * This method is affected by the active fetch flag set using
     * `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * $robots = $result->fetchAll();
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
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 179,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 179,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 178,
          'last-line' => 219,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchArray',
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
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 222,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pdoStatement',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 222,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 222,
                  'char' => 35,
                ),
                'name' => 'fetch',
                'call-type' => 1,
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 222,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of strings that corresponds to the fetched row, or FALSE
     * if there are no more rows. This method is affected by the active fetch
     * flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM robots ORDER BY name");
     *
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_NUM
     * );
     *
     * while ($robot = result->fetchArray()) {
     *     print_r($robot);
     * }
     *```
     *',
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 220,
          'last-line' => 227,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInternalResult',
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
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 230,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'pdoStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 230,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 230,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 231,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the internal PDO result object
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
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 229,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 229,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 228,
          'last-line' => 243,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'numRows',
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
                  'variable' => 'sqlStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'rowCount',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 53,
                ),
                4 => 
                array (
                  'variable' => 'pdoStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 67,
                ),
                5 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 246,
                  'char' => 76,
                ),
                6 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 247,
                  'char' => 19,
                ),
                7 => 
                array (
                  'variable' => 'row',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 247,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 249,
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
                  'variable' => 'rowCount',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 249,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rowCount',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 249,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 249,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 249,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 251,
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
                  'type' => 'variable',
                  'value' => 'rowCount',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 251,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 251,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 251,
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
                      'variable' => 'connection',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 252,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 252,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 252,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 252,
                      'char' => 46,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'type',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 253,
                          'char' => 35,
                        ),
                        'name' => 'getType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 253,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 253,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 258,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 258,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'mysql',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 258,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 258,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 258,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'pgsql',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 258,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 258,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'pdoStatement',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 259,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'pdoStatement',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 259,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 259,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 259,
                          'char' => 54,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'rowCount',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'pdoStatement',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 260,
                              'char' => 45,
                            ),
                            'name' => 'rowCount',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 260,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 260,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 261,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 266,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rowCount',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 266,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 266,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 266,
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
                          'operator' => 'assign',
                          'variable' => 'sqlStatement',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 272,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sqlStatement',
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 272,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 272,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 272,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 278,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'starts_with',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sqlStatement',
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 278,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 278,
                              'char' => 45,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'SELECT COUNT(*) ',
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 278,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 278,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 278,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 278,
                        'char' => 65,
                      ),
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
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 279,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 279,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 281,
                          'char' => 22,
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
                                  'type' => 'string',
                                  'value' => '/^SELECT\\\\s+(.*)/i',
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 281,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 281,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sqlStatement',
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 281,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 281,
                                'char' => 67,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'matches',
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 281,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 281,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 281,
                            'char' => 78,
                          ),
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
                                  'variable' => 'result',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'connection',
                                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                      'line' => 282,
                                      'char' => 49,
                                    ),
                                    'name' => 'query',
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
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'SELECT COUNT(*) \\"numrows\\" FROM (SELECT ',
                                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                              'line' => 283,
                                              'char' => 71,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'matches',
                                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                                'line' => 283,
                                                'char' => 80,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'int',
                                                'value' => '1',
                                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                                'line' => 283,
                                                'char' => 82,
                                              ),
                                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                              'line' => 283,
                                              'char' => 84,
                                            ),
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 283,
                                            'char' => 84,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => ')',
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 283,
                                            'char' => 87,
                                          ),
                                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                          'line' => 283,
                                          'char' => 87,
                                        ),
                                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                        'line' => 283,
                                        'char' => 87,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'property-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 284,
                                            'char' => 34,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'bindParams',
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 284,
                                            'char' => 45,
                                          ),
                                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                          'line' => 284,
                                          'char' => 45,
                                        ),
                                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                        'line' => 284,
                                        'char' => 45,
                                      ),
                                      2 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'property-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 285,
                                            'char' => 34,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'bindTypes',
                                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                            'line' => 286,
                                            'char' => 25,
                                          ),
                                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                          'line' => 286,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                        'line' => 286,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                    'line' => 286,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 286,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 288,
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
                                  'variable' => 'row',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'result',
                                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                      'line' => 288,
                                      'char' => 42,
                                    ),
                                    'name' => 'fetch',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                    'line' => 288,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 288,
                                  'char' => 50,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'rowCount',
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'row',
                                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                      'line' => 289,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'numrows',
                                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                      'line' => 289,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                    'line' => 289,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                  'line' => 289,
                                  'char' => 52,
                                ),
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 290,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 291,
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
                              'operator' => 'assign',
                              'variable' => 'rowCount',
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 292,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 292,
                              'char' => 37,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 293,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 294,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 299,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'rowCount',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'rowCount',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 299,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 299,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 300,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 302,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'rowCount',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 302,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 303,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets number of rows returned by a resultset
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * echo "There are ", $result->numRows(), " rows in the resultset";
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
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 245,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 245,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 244,
          'last-line' => 329,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFetchMode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 330,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'colNoOrClassNameOrObject',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 330,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 330,
              'char' => 84,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ctorargs',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 330,
                'char' => 105,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 330,
              'char' => 105,
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
                  'variable' => 'pdoStatement',
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 332,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 334,
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
                  'variable' => 'pdoStatement',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 334,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pdoStatement',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 334,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 334,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 334,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 336,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fetchMode',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 336,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Db',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 336,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'FETCH_CLASS',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 336,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 336,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 336,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fetchMode',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 336,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Db',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 336,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'FETCH_INTO',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 336,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 336,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 336,
                  'char' => 72,
                ),
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 336,
                'char' => 72,
              ),
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pdoStatement',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 337,
                        'char' => 30,
                      ),
                      'name' => 'setFetchMode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fetchMode',
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 337,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 337,
                          'char' => 53,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'colNoOrClassNameOrObject',
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 337,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 337,
                          'char' => 79,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ctorargs',
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 337,
                            'char' => 89,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 337,
                          'char' => 89,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 337,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 337,
                    'char' => 91,
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
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 338,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 339,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 340,
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
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fetchMode',
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 340,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Db',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 340,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'FETCH_COLUMN',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 340,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 340,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 340,
                    'char' => 48,
                  ),
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pdoStatement',
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 341,
                            'char' => 30,
                          ),
                          'name' => 'setFetchMode',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'fetchMode',
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 341,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 341,
                              'char' => 53,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'colNoOrClassNameOrObject',
                                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                                'line' => 341,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Db/Result/Pdo.zep',
                              'line' => 341,
                              'char' => 79,
                            ),
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 341,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 341,
                        'char' => 81,
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
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 342,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 343,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 344,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 344,
                  'char' => 14,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pdoStatement',
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 345,
                        'char' => 30,
                      ),
                      'name' => 'setFetchMode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fetchMode',
                            'file' => '/app/phalcon/Db/Result/Pdo.zep',
                            'line' => 345,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Result/Pdo.zep',
                          'line' => 345,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 345,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 345,
                    'char' => 55,
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
                        'file' => '/app/phalcon/Db/Result/Pdo.zep',
                        'line' => 346,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Db/Result/Pdo.zep',
                      'line' => 347,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 348,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 350,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'fetchMode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fetchMode',
                    'file' => '/app/phalcon/Db/Result/Pdo.zep',
                    'line' => 350,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Result/Pdo.zep',
                  'line' => 350,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 352,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 352,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Result/Pdo.zep',
              'line' => 353,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes the fetching mode affecting Phalcon\\Db\\Result\\Pdo::fetch()
     *
     *```php
     * // Return array with integer indexes
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_NUM
     * );
     *
     * // Return associative array without integer indexes
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_ASSOC
     * );
     *
     * // Return associative array together with integer indexes
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_BOTH
     * );
     *
     * // Return an object
     * $result->setFetchMode(
     *     \\Phalcon\\Db::FETCH_OBJ
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
                'file' => '/app/phalcon/Db/Result/Pdo.zep',
                'line' => 331,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Result/Pdo.zep',
            'line' => 331,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Result/Pdo.zep',
          'line' => 330,
          'last-line' => 354,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/Result/Pdo.zep',
      'line' => 34,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Result/Pdo.zep',
    'line' => 34,
    'char' => 5,
  ),
);