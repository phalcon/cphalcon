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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData\\Strategy',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\Db\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 15,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 19,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
    'line' => 25,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Strategy\\Introspection
 *
 * Queries the table meta-data in order to introspect the model\'s metadata
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
    'line' => 26,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Introspection',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
        'line' => 27,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnMaps',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 31,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 31,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 31,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 31,
              'char' => 88,
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
                  'variable' => 'orderedColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 33,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'userColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 33,
                  'char' => 44,
                ),
                2 => 
                array (
                  'variable' => 'reversedColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 33,
                  'char' => 63,
                ),
                3 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 33,
                  'char' => 69,
                ),
                4 => 
                array (
                  'variable' => 'userName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 33,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 35,
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
                  'variable' => 'orderedColumnMap',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 35,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 35,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 36,
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
                  'variable' => 'reversedColumnMap',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 36,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 36,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 41,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 41,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 41,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'columnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 41,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 41,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 41,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'userColumnMap',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 42,
                          'char' => 39,
                        ),
                        'name' => 'columnMap',
                        'call-type' => 3,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 42,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 42,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 44,
                  'char' => 14,
                ),
                1 => 
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
                          'value' => 'userColumnMap',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 44,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 44,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 44,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 44,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 44,
                    'char' => 55,
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
                              'value' => 'columnMap() not returned an array',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 45,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 45,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 45,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 46,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 48,
                  'char' => 15,
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
                      'variable' => 'reversedColumnMap',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 48,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 48,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'orderedColumnMap',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'userColumnMap',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 49,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 49,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 51,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'userColumnMap',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 51,
                    'char' => 49,
                  ),
                  'key' => 'name',
                  'value' => 'userName',
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
                          'variable' => 'reversedColumnMap',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'userName',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 52,
                              'char' => 47,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'name',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 52,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 52,
                          'char' => 55,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 53,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 54,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 59,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'orderedColumnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 59,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 59,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reversedColumnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 59,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 59,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 59,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Read the model\'s column map, this can\'t be inferred
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 32,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
          'line' => 31,
          'last-line' => 64,
          'char' => 25,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMetaData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 65,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 65,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 65,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 65,
              'char' => 86,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'table',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'readConnection',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 63,
                ),
                5 => 
                array (
                  'variable' => 'primaryKeys',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 67,
                  'char' => 76,
                ),
                6 => 
                array (
                  'variable' => 'nonPrimaryKeys',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 68,
                  'char' => 27,
                ),
                7 => 
                array (
                  'variable' => 'numericTyped',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 68,
                  'char' => 41,
                ),
                8 => 
                array (
                  'variable' => 'notNull',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 68,
                  'char' => 50,
                ),
                9 => 
                array (
                  'variable' => 'fieldTypes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 68,
                  'char' => 62,
                ),
                10 => 
                array (
                  'variable' => 'automaticDefault',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 68,
                  'char' => 80,
                ),
                11 => 
                array (
                  'variable' => 'identityField',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 69,
                  'char' => 26,
                ),
                12 => 
                array (
                  'variable' => 'fieldBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 69,
                  'char' => 42,
                ),
                13 => 
                array (
                  'variable' => 'defaultValues',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 69,
                  'char' => 57,
                ),
                14 => 
                array (
                  'variable' => 'column',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 69,
                  'char' => 65,
                ),
                15 => 
                array (
                  'variable' => 'fieldName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 69,
                  'char' => 76,
                ),
                16 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 70,
                  'char' => 25,
                ),
                17 => 
                array (
                  'variable' => 'emptyStringValues',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 70,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 71,
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
                  'variable' => 'completeTable',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 71,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 73,
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
                  'variable' => 'schema',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 73,
                      'char' => 28,
                    ),
                    'name' => 'getSchema',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 73,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 73,
                  'char' => 40,
                ),
                1 => 
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
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 74,
                      'char' => 28,
                    ),
                    'name' => 'getSource',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 74,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 74,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 79,
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
                  'variable' => 'readConnection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 79,
                      'char' => 36,
                    ),
                    'name' => 'getReadConnection',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 79,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 79,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 81,
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'readConnection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 81,
                      'char' => 37,
                    ),
                    'name' => 'tableExists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'table',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 81,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 81,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schema',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 81,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 81,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 81,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 81,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 81,
                'char' => 65,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'schema',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 82,
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
                          'variable' => 'completeTable',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 83,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\'.\'',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 83,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 83,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'table',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 83,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 83,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 83,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 84,
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
                          'variable' => 'completeTable',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 85,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 85,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 86,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 91,
                  'char' => 17,
                ),
                1 => 
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'Table \'',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 92,
                                'char' => 25,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'completeTable',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 92,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 92,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\' doesn\'t exist in database when dumping meta-data for ',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 92,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 92,
                            'char' => 99,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'get_class',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'model',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                  'line' => 92,
                                  'char' => 116,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 92,
                                'char' => 116,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 93,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 93,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 93,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 93,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 99,
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
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'readConnection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 99,
                      'char' => 38,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 99,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 99,
                        'char' => 60,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schema',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 99,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 99,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 99,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 99,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 101,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 101,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 101,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 101,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 101,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 101,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'schema',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 102,
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
                          'variable' => 'completeTable',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'schema',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 103,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\'.\'',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 103,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 103,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'table',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 103,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 103,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 103,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 104,
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
                          'variable' => 'completeTable',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'table',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 105,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 105,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 106,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 111,
                  'char' => 17,
                ),
                1 => 
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'Cannot obtain table columns for the mapped source \'',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 112,
                                'char' => 69,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'completeTable',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 112,
                                'char' => 85,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 112,
                              'char' => 85,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\' used in model ',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 112,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 112,
                            'char' => 104,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'get_class',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'model',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                  'line' => 112,
                                  'char' => 121,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 112,
                                'char' => 121,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 113,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 113,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 113,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 113,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 119,
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
                  'variable' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 119,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 119,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 120,
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
                  'variable' => 'primaryKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 120,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 120,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 121,
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
                  'variable' => 'nonPrimaryKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 121,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 121,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 122,
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
                  'variable' => 'numericTyped',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 122,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 122,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 123,
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
                  'variable' => 'notNull',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 123,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 123,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 124,
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
                  'variable' => 'fieldTypes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 124,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 124,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 125,
              'char' => 11,
            ),
            13 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fieldBindTypes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 125,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 125,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 126,
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
                  'operator' => 'assign',
                  'variable' => 'automaticDefault',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 126,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 126,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 127,
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
                  'operator' => 'assign',
                  'variable' => 'identityField',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 127,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 127,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 128,
              'char' => 11,
            ),
            16 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'defaultValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 128,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 128,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 129,
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
                  'operator' => 'assign',
                  'variable' => 'emptyStringValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 129,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 129,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 131,
              'char' => 11,
            ),
            18 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 131,
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
                      'variable' => 'fieldName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 132,
                          'char' => 36,
                        ),
                        'name' => 'getName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 132,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 132,
                      'char' => 46,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'attributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'fieldName',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 133,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 133,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 138,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 138,
                      'char' => 23,
                    ),
                    'name' => 'isPrimary',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 138,
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
                          'variable' => 'primaryKeys',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fieldName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 139,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 139,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 140,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'nonPrimaryKeys',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fieldName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 141,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 141,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 142,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 147,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 147,
                      'char' => 23,
                    ),
                    'name' => 'isNumeric',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 147,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'numericTyped',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'fieldName',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 148,
                              'char' => 43,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 148,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 148,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 149,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 154,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 154,
                      'char' => 23,
                    ),
                    'name' => 'isNotNull',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 154,
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
                          'variable' => 'notNull',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fieldName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 155,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 155,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 156,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 161,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 161,
                      'char' => 23,
                    ),
                    'name' => 'isAutoIncrement',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 161,
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
                          'operator' => 'assign',
                          'variable' => 'identityField',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fieldName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 162,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 162,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 163,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 168,
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
                      'variable' => 'fieldTypes',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'fieldName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 168,
                          'char' => 37,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 168,
                          'char' => 48,
                        ),
                        'name' => 'getType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 168,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 168,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 173,
                  'char' => 15,
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
                      'variable' => 'fieldBindTypes',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'fieldName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 173,
                          'char' => 41,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 173,
                          'char' => 52,
                        ),
                        'name' => 'getBindType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 173,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 173,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 178,
                  'char' => 15,
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
                      'variable' => 'defaultValue',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'column',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 178,
                          'char' => 39,
                        ),
                        'name' => 'getDefault',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 178,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 178,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 180,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultValue',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 180,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 180,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 180,
                      'char' => 39,
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
                          'value' => 'column',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 180,
                          'char' => 49,
                        ),
                        'name' => 'isNotNull',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 180,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 180,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 180,
                    'char' => 62,
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
                            'value' => 'column',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                            'line' => 181,
                            'char' => 28,
                          ),
                          'name' => 'isAutoIncrement',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 181,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 181,
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
                              'variable' => 'defaultValues',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fieldName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                  'line' => 182,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'defaultValue',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                                'line' => 182,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                              'line' => 182,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                          'line' => 183,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 184,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                  'line' => 185,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 190,
              'char' => 14,
            ),
            19 => 
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
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 191,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_ATTRIBUTES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 191,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 191,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 191,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 191,
                    'char' => 67,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 192,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_PRIMARY_KEY',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 192,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 192,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'primaryKeys',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 192,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 192,
                    'char' => 68,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 193,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_NON_PRIMARY_KEY',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 193,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 193,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nonPrimaryKeys',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 193,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 193,
                    'char' => 71,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 194,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_NOT_NULL',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 194,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 194,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notNull',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 194,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 194,
                    'char' => 64,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 195,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 195,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 195,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fieldTypes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 195,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 195,
                    'char' => 67,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 196,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES_NUMERIC',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 196,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 196,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'numericTyped',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 196,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 196,
                    'char' => 69,
                  ),
                  6 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 197,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_IDENTITY_COLUMN',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 197,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 197,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'identityField',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 197,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 197,
                    'char' => 70,
                  ),
                  7 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 198,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES_BIND',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 198,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 198,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fieldBindTypes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 198,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 198,
                    'char' => 71,
                  ),
                  8 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 199,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_INSERT',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 199,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 199,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'automaticDefault',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 199,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 199,
                    'char' => 73,
                  ),
                  9 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 200,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_UPDATE',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 200,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 200,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'automaticDefault',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 200,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 200,
                    'char' => 73,
                  ),
                  10 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 201,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DEFAULT_VALUES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 201,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 201,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValues',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 201,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 201,
                    'char' => 70,
                  ),
                  11 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MetaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 202,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_EMPTY_STRING_VALUES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                        'line' => 202,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 202,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'emptyStringValues',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                      'line' => 203,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                    'line' => 203,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 203,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
              'line' => 204,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * The meta-data is obtained by reading the column descriptions from the database information schema
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
          'line' => 65,
          'last-line' => 205,
          'char' => 25,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Introspection.zep',
    'line' => 26,
    'char' => 5,
  ),
);