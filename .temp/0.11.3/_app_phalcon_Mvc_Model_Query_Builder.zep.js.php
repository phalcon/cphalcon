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
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Query',
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 16,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 18,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\QueryInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 19,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Query\\BuilderInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 20,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
    'line' => 57,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Query\\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *```php
 * $params = [
 *     "models"     => [
 *         Users::class,
 *     ],
 *     "columns"    => ["id", "name", "status"],
 *     "conditions" => [
 *         [
 *             "created > :min: AND created < :max:",
 *             [
 *                 "min" => "2013-01-01",
 *                 "max" => "2014-01-01",
 *             ],
 *             [
 *                 "min" => PDO::PARAM_STR,
 *                 "max" => PDO::PARAM_STR,
 *             ],
 *         ],
 *     ],
 *     // or "conditions" => "created > \'2013-01-01\' AND created < \'2014-01-01\'",
 *     "group"      => ["id", "name"],
 *     "having"     => "name = \'Kamil\'",
 *     "order"      => ["name", "id"],
 *     "limit"      => 20,
 *     "offset"     => 20,
 *     // or "limit" => [20, 20],
 * ];
 *
 * $queryBuilder = new \\Phalcon\\Mvc\\Model\\Query\\Builder($params);
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
    'line' => 58,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'Builder',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'BuilderInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 58,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
        'line' => 59,
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
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 61,
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
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 62,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'columns',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 63,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'conditions',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 64,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 65,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'distinct',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 66,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'forUpdate',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 70,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'group',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 73,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'having',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 74,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'hiddenParamNumber',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 74,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 75,
          'char' => 13,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'joins',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 76,
          'char' => 13,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'limit',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 77,
          'char' => 13,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'models',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 78,
          'char' => 13,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'offset',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 79,
          'char' => 13,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'order',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 80,
          'char' => 13,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sharedLock',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 84,
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
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 85,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 85,
              'char' => 50,
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 85,
                'char' => 74,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 85,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 85,
              'char' => 82,
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
                  'variable' => 'conditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 87,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 87,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'groupClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 87,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'havingClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 87,
                  'char' => 59,
                ),
                4 => 
                array (
                  'variable' => 'limitClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 87,
                  'char' => 72,
                ),
                5 => 
                array (
                  'variable' => 'forUpdate',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 88,
                  'char' => 22,
                ),
                6 => 
                array (
                  'variable' => 'sharedLock',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 88,
                  'char' => 34,
                ),
                7 => 
                array (
                  'variable' => 'orderClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 88,
                  'char' => 47,
                ),
                8 => 
                array (
                  'variable' => 'offsetClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 88,
                  'char' => 61,
                ),
                9 => 
                array (
                  'variable' => 'joinsClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 88,
                  'char' => 74,
                ),
                10 => 
                array (
                  'variable' => 'singleConditionArray',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 89,
                  'char' => 33,
                ),
                11 => 
                array (
                  'variable' => 'limit',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 89,
                  'char' => 40,
                ),
                12 => 
                array (
                  'variable' => 'offset',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 89,
                  'char' => 48,
                ),
                13 => 
                array (
                  'variable' => 'fromClause',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 89,
                  'char' => 60,
                ),
                14 => 
                array (
                  'variable' => 'singleCondition',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 89,
                  'char' => 77,
                ),
                15 => 
                array (
                  'variable' => 'singleParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 90,
                  'char' => 25,
                ),
                16 => 
                array (
                  'variable' => 'singleTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 90,
                  'char' => 38,
                ),
                17 => 
                array (
                  'variable' => 'distinct',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 90,
                  'char' => 48,
                ),
                18 => 
                array (
                  'variable' => 'bind',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 90,
                  'char' => 54,
                ),
                19 => 
                array (
                  'variable' => 'bindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 90,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
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
                  'variable' => 'mergedConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 91,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'mergedParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 91,
                  'char' => 45,
                ),
                2 => 
                array (
                  'variable' => 'mergedTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 91,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 93,
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 93,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 93,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 93,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 93,
                'char' => 35,
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
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 97,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 97,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 97,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 97,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 97,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'conditions',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 98,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 98,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 99,
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
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 100,
                          'char' => 57,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 100,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 100,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 100,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 100,
                        'char' => 57,
                      ),
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
                              'property' => 'conditions',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'conditions',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 101,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 101,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 102,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 105,
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
                        'value' => 'conditions',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 105,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 105,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 105,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 105,
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
                          'variable' => 'mergedConditions',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 106,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 106,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 107,
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
                          'variable' => 'mergedParams',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 107,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 107,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 108,
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
                          'variable' => 'mergedTypes',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 108,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 108,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 110,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'conditions',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 110,
                        'char' => 56,
                      ),
                      'value' => 'singleConditionArray',
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
                                'value' => 'singleConditionArray',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 111,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 111,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 111,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 111,
                            'char' => 61,
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
                                  'value' => 'singleCondition',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 112,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'singleConditionArray',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 112,
                                    'char' => 68,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 112,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 112,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 112,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 113,
                              'char' => 29,
                            ),
                            1 => 
                            array (
                              'type' => 'fetch',
                              'expr' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleParams',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 113,
                                  'char' => 68,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'singleConditionArray',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 113,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 113,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 113,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 113,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 114,
                              'char' => 29,
                            ),
                            2 => 
                            array (
                              'type' => 'fetch',
                              'expr' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleTypes',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 114,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'singleConditionArray',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 114,
                                    'char' => 64,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 114,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 114,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 114,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 116,
                              'char' => 26,
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
                                    'value' => 'singleCondition',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 116,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 116,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'string',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 116,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 116,
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
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'mergedConditions',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'singleCondition',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 117,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 117,
                                      'char' => 69,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 118,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 120,
                              'char' => 26,
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
                                    'value' => 'singleParams',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 120,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 120,
                                  'char' => 49,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 120,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 120,
                                'char' => 57,
                              ),
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
                                      'variable' => 'mergedParams',
                                      'expr' => 
                                      array (
                                        'type' => 'add',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'mergedParams',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 121,
                                          'char' => 61,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'singleParams',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 121,
                                          'char' => 75,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 121,
                                        'char' => 75,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 121,
                                      'char' => 75,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 122,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 124,
                              'char' => 26,
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
                                    'value' => 'singleTypes',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 124,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 124,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 124,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 124,
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
                                      'operator' => 'assign',
                                      'variable' => 'mergedTypes',
                                      'expr' => 
                                      array (
                                        'type' => 'add',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'mergedTypes',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 125,
                                          'char' => 59,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'singleTypes',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 125,
                                          'char' => 72,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 125,
                                        'char' => 72,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 125,
                                      'char' => 72,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 126,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 127,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 128,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 130,
                      'char' => 19,
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
                          'property' => 'conditions',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'implode',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' AND ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 130,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 130,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'mergedConditions',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 130,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 130,
                                'char' => 71,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 130,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 130,
                          'char' => 72,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 132,
                      'char' => 19,
                    ),
                    5 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mergedParams',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 132,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 132,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 133,
                      'char' => 19,
                    ),
                    6 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mergedTypes',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 133,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 133,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 134,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 139,
                  'char' => 14,
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
                      'value' => 'bind',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 139,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 139,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'bind',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 139,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 139,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 139,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bind',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 140,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 140,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 141,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 143,
                  'char' => 14,
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
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 143,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 143,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 143,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 143,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 143,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindTypes',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 144,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 144,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 145,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 150,
                  'char' => 14,
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
                      'value' => 'distinct',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 150,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 150,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'distinct',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 150,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 150,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 150,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'distinct',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'distinct',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 151,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 151,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 152,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 157,
                  'char' => 14,
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
                      'value' => 'fromClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 157,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 157,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'models',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 157,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 157,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 157,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'models',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fromClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 158,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 158,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 159,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 164,
                  'char' => 14,
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
                      'value' => 'columns',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 164,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 164,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 164,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 164,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 164,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'columns',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columns',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 165,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 165,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 166,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 171,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'joinsClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 171,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 171,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'joins',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 171,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 171,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 171,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'joins',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'joinsClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 172,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 172,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 173,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 178,
                  'char' => 14,
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
                      'value' => 'groupClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 178,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 178,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'group',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 178,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 178,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 178,
                    'char' => 49,
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
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 179,
                          'char' => 22,
                        ),
                        'name' => 'groupBy',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'groupClause',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 179,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 179,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 179,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 180,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 185,
                  'char' => 14,
                ),
                9 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'havingClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 185,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 185,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'having',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 185,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 185,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 185,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'having',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'havingClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 186,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 186,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 187,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 192,
                  'char' => 14,
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
                      'value' => 'orderClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 192,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 192,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'order',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 192,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 192,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 192,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'order',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'orderClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 193,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 193,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 194,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 199,
                  'char' => 14,
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
                      'value' => 'limitClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 199,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 199,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'limit',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 199,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 199,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 199,
                    'char' => 49,
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
                            'value' => 'limitClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 200,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 200,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 200,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 200,
                        'char' => 48,
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
                              'value' => 'limit',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 201,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'limitClause',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 201,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 201,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 201,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 201,
                            'char' => 52,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'is_int',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'limit',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 202,
                                      'char' => 40,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 202,
                                    'char' => 40,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 202,
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
                                      'assign-type' => 'object-property',
                                      'operator' => 'assign',
                                      'variable' => 'this',
                                      'property' => 'limit',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'limit',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 203,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 203,
                                      'char' => 52,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 204,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 206,
                              'char' => 26,
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
                                  'value' => 'offset',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 206,
                                  'char' => 57,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'limitClause',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 206,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 206,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 206,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 206,
                                'char' => 57,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'if',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'is_int',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'offset',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 207,
                                          'char' => 45,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 207,
                                        'char' => 45,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 207,
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
                                          'assign-type' => 'object-property',
                                          'operator' => 'assign',
                                          'variable' => 'this',
                                          'property' => 'offset',
                                          'expr' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'offset',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 208,
                                            'char' => 58,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 208,
                                          'char' => 58,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 209,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 210,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 211,
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
                                  'assign-type' => 'object-property',
                                  'operator' => 'assign',
                                  'variable' => 'this',
                                  'property' => 'limit',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'limitClause',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 212,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 212,
                                  'char' => 54,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 213,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 214,
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
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'limit',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'limitClause',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 215,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 215,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 216,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 217,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 222,
                  'char' => 14,
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
                      'value' => 'offsetClause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 222,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 222,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'offset',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 222,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 222,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 222,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'offset',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'offsetClause',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 223,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 223,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 224,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 229,
                  'char' => 14,
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
                      'value' => 'forUpdate',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 229,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 229,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'for_update',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 229,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 229,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 229,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'forUpdate',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'forUpdate',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 230,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 230,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 231,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 236,
                  'char' => 14,
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
                      'value' => 'sharedLock',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 236,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 236,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'shared_lock',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 236,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 236,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 236,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'sharedLock',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sharedLock',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 237,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 237,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 238,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 239,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 240,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 240,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 240,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 240,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 240,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 240,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 240,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 240,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'conditions',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 241,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 241,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 242,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 243,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 248,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 248,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 248,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 249,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Query\\Builder constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 85,
          'last-line' => 266,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addFrom',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 267,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 267,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 267,
              'char' => 62,
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
                  'variable' => 'models',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 269,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'currentModel',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 269,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 271,
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
                  'variable' => 'models',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 271,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'models',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 271,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 271,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 271,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 273,
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
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 273,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 273,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 273,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 273,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'models',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 274,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 274,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 274,
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
                          'variable' => 'currentModel',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'models',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 275,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 275,
                          'char' => 42,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'models',
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
                                  'value' => 'currentModel',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 276,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 276,
                                'char' => 43,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 276,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 276,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 277,
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
                          'variable' => 'models',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 278,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 278,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 279,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 280,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 282,
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
                    'value' => 'alias',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 282,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 282,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 282,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 282,
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
                      'variable' => 'models',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 283,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'model',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 283,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 283,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 284,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'models',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'model',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 285,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 285,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 286,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 288,
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
                  'property' => 'models',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 288,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 288,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 290,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 290,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 291,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Add a model to take part of the query
     *
     *```php
     * // Load data from models Robots
     * $builder->addFrom(
     *     Robots::class
     * );
     *
     * // Load data from model \'Robots\' using \'r\' as alias in PHQL
     * $builder->addFrom(
     *     Robots::class,
     *     "r"
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 268,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 268,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 268,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 267,
          'last-line' => 306,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'andHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 307,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 307,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 307,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 307,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 307,
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
                  'variable' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 309,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 311,
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
                  'variable' => 'currentConditions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 311,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 311,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 311,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 311,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 316,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'currentConditions',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 316,
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
                      'operator' => 'assign',
                      'variable' => 'conditions',
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
                                'value' => '(',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 317,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 317,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 317,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') AND (',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 317,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 317,
                            'char' => 62,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 317,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 317,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 317,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 317,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 317,
                      'char' => 78,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 318,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 320,
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 320,
                  'char' => 21,
                ),
                'name' => 'having',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 320,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 320,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 320,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 320,
                    'char' => 51,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 320,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 320,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 320,
                'char' => 63,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 321,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current HAVING conditions clause using a AND operator
     *
     *```php
     * $builder->andHaving("SUM(Robots.price) > 0");
     *
     * $builder->andHaving(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 308,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 308,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 308,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 307,
          'last-line' => 337,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'andWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 338,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 338,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 338,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 338,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 338,
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
                  'variable' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 340,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 342,
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
                  'variable' => 'currentConditions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 342,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 342,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 342,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 342,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 347,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'currentConditions',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 347,
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
                      'operator' => 'assign',
                      'variable' => 'conditions',
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
                                'value' => '(',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 348,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 348,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 348,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') AND (',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 348,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 348,
                            'char' => 62,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 348,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 348,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 348,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 348,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 348,
                      'char' => 78,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 349,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 351,
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 351,
                  'char' => 21,
                ),
                'name' => 'where',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 351,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 351,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 351,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 351,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 351,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 351,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 351,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 352,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current WHERE conditions using a AND operator
     *
     *```php
     * $builder->andWhere("name = \'Peter\'");
     *
     * $builder->andWhere(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 339,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 339,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 339,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 338,
          'last-line' => 356,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'autoescape',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'identifier',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 357,
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
                'type' => 'or',
                'left' => 
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
                          'value' => 'identifier',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 359,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 359,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '[',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 359,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 359,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 359,
                    'char' => 35,
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
                          'value' => 'identifier',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 359,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 359,
                        'char' => 54,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '.',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 359,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 359,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 359,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 359,
                  'char' => 60,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_numeric',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'identifier',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 359,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 359,
                      'char' => 83,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 359,
                  'char' => 85,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 359,
                'char' => 85,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'identifier',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 360,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 361,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 363,
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
                    'value' => '[',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 363,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'identifier',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 363,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 363,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => ']',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 363,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 363,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 364,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Automatically escapes identifiers but only if they need to be escaped.
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 358,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 358,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 357,
          'last-line' => 372,
          'char' => 25,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'betweenHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 373,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 373,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 373,
              'char' => 73,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 373,
                  'char' => 124,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 373,
                  'char' => 124,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 373,
                'char' => 124,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 373,
              'char' => 124,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 375,
                  'char' => 21,
                ),
                'name' => 'conditionBetween',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 375,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 375,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 375,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 375,
                    'char' => 55,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 375,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 375,
                    'char' => 61,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'minimum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 375,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 375,
                    'char' => 70,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'maximum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 375,
                      'char' => 79,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 375,
                    'char' => 79,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 375,
                'char' => 80,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 376,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 374,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 374,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 374,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 373,
          'last-line' => 384,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'betweenWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 385,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 385,
              'char' => 59,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 385,
              'char' => 72,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 385,
                  'char' => 123,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 385,
                  'char' => 123,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 385,
                'char' => 123,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 385,
              'char' => 123,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 387,
                  'char' => 21,
                ),
                'name' => 'conditionBetween',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Where',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 387,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 387,
                    'char' => 44,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 387,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 387,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 387,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 387,
                    'char' => 60,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'minimum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 387,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 387,
                    'char' => 69,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'maximum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 387,
                      'char' => 78,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 387,
                    'char' => 78,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 387,
                'char' => 79,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 388,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition to the current WHERE conditions
     *
     *```php
     * $builder->betweenWhere("price", 100.25, 200.50);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 386,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 386,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 386,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 385,
          'last-line' => 410,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'columns',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'columns',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 411,
              'char' => 40,
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
                  'property' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 413,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 413,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 415,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 415,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 416,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the columns to be queried
     *
     *```php
     * $builder->columns("id, name");
     *
     * $builder->columns(
     *     [
     *         "id",
     *         "name",
     *     ]
     * );
     *
     * $builder->columns(
     *     [
     *         "name",
     *         "number" => "COUNT(*)",
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 412,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 412,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 412,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 411,
          'last-line' => 425,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'distinct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'distinct',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 426,
              'char' => 42,
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
                  'property' => 'distinct',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'distinct',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 428,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 428,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 430,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 430,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 431,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets SELECT DISTINCT / SELECT ALL flag
     *
     *```php
     * $builder->distinct("status");
     * $builder->distinct(null);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 427,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 427,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 427,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 426,
          'last-line' => 439,
          'char' => 19,
        ),
        9 => 
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
              'name' => 'forUpdate',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 440,
              'char' => 45,
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
                  'property' => 'forUpdate',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'forUpdate',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 442,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 442,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 444,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 444,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 445,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a FOR UPDATE clause
     *
     *```php
     * $builder->forUpdate(true);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 441,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 441,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 441,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 440,
          'last-line' => 469,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'from',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'models',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 470,
              'char' => 36,
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
                  'property' => 'models',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 472,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 472,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 474,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 474,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 475,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the models who makes part of the query
     *
     *```php
     * $builder->from(
     *     Robots::class
     * );
     *
     * $builder->from(
     *     [
     *         Robots::class,
     *         RobotsParts::class,
     *     ]
     * );
     *
     * $builder->from(
     *     [
     *         "r"  => Robots::class,
     *         "rp" => RobotsParts::class,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 471,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 471,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 471,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 470,
          'last-line' => 479,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindParams',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 482,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 482,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 482,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 483,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns default bind params
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 481,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 481,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 480,
          'last-line' => 487,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindTypes',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 490,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'bindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 490,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 490,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 491,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns default bind types
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 489,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 489,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 488,
          'last-line' => 497,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumns',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 500,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 500,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 500,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 501,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the columns to be queried
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 498,
          'last-line' => 505,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 508,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 508,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 508,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 509,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the DependencyInjector container
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 507,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 507,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 507,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 506,
          'last-line' => 513,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDistinct',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 516,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'distinct',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 516,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 516,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 517,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns SELECT DISTINCT / SELECT ALL flag
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 515,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 515,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 514,
          'last-line' => 523,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFrom',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 526,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'models',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 526,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 526,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 527,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the models who makes part of the query
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 524,
          'last-line' => 531,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getGroupBy',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 534,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'group',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 534,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 534,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 535,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the GROUP BY clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 533,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 533,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 532,
          'last-line' => 539,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHaving',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 542,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'having',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 542,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 542,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 543,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the current having clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 541,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 541,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 540,
          'last-line' => 547,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getJoins',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 550,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'joins',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 550,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 550,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 551,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return join parts of the query
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 549,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 549,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 548,
          'last-line' => 557,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLimit',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 560,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'limit',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 560,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 560,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 561,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current LIMIT clause
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 558,
          'last-line' => 565,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModels',
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
                  'variable' => 'models',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 568,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'models',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 568,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 568,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 568,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 570,
              'char' => 10,
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
                      'value' => 'models',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 570,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 570,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 570,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 570,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'equals',
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
                          'value' => 'models',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 570,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 570,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 570,
                    'char' => 53,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 570,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 570,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 570,
                'char' => 57,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'first',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'models',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 571,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 571,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 571,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 572,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 574,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'models',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 574,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 575,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the models involved in the query
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 566,
                'char' => 43,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 566,
                'char' => 51,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 567,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 567,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 566,
          'last-line' => 579,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOffset',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 582,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'offset',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 582,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 582,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 583,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current OFFSET clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 581,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 581,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 580,
          'last-line' => 589,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOrderBy',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 592,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'order',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 592,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 592,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 593,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the set ORDER BY clause
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 590,
          'last-line' => 597,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPhql',
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'models',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'conditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'metaData',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'modelInstance',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 600,
                  'char' => 74,
                ),
                6 => 
                array (
                  'variable' => 'primaryKeys',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 601,
                  'char' => 24,
                ),
                7 => 
                array (
                  'variable' => 'firstPrimaryKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 601,
                  'char' => 41,
                ),
                8 => 
                array (
                  'variable' => 'columnMap',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 601,
                  'char' => 52,
                ),
                9 => 
                array (
                  'variable' => 'modelAlias',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 601,
                  'char' => 64,
                ),
                10 => 
                array (
                  'variable' => 'attributeField',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 602,
                  'char' => 27,
                ),
                11 => 
                array (
                  'variable' => 'phql',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 602,
                  'char' => 33,
                ),
                12 => 
                array (
                  'variable' => 'column',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 602,
                  'char' => 41,
                ),
                13 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 602,
                  'char' => 50,
                ),
                14 => 
                array (
                  'variable' => 'selectedColumns',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 602,
                  'char' => 67,
                ),
                15 => 
                array (
                  'variable' => 'selectedColumn',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 603,
                  'char' => 27,
                ),
                16 => 
                array (
                  'variable' => 'selectedModel',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 603,
                  'char' => 42,
                ),
                17 => 
                array (
                  'variable' => 'selectedModels',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 603,
                  'char' => 58,
                ),
                18 => 
                array (
                  'variable' => 'columnAlias',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 603,
                  'char' => 71,
                ),
                19 => 
                array (
                  'variable' => 'modelColumnAlias',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 604,
                  'char' => 29,
                ),
                20 => 
                array (
                  'variable' => 'joins',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 604,
                  'char' => 36,
                ),
                21 => 
                array (
                  'variable' => 'join',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 604,
                  'char' => 42,
                ),
                22 => 
                array (
                  'variable' => 'joinModel',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 604,
                  'char' => 53,
                ),
                23 => 
                array (
                  'variable' => 'joinConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 604,
                  'char' => 69,
                ),
                24 => 
                array (
                  'variable' => 'joinAlias',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 22,
                ),
                25 => 
                array (
                  'variable' => 'joinType',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 32,
                ),
                26 => 
                array (
                  'variable' => 'group',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 39,
                ),
                27 => 
                array (
                  'variable' => 'groupItems',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 51,
                ),
                28 => 
                array (
                  'variable' => 'groupItem',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 62,
                ),
                29 => 
                array (
                  'variable' => 'having',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 70,
                ),
                30 => 
                array (
                  'variable' => 'order',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 605,
                  'char' => 77,
                ),
                31 => 
                array (
                  'variable' => 'orderItems',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 23,
                ),
                32 => 
                array (
                  'variable' => 'orderItem',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 34,
                ),
                33 => 
                array (
                  'variable' => 'limit',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 41,
                ),
                34 => 
                array (
                  'variable' => 'number',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 49,
                ),
                35 => 
                array (
                  'variable' => 'offset',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 57,
                ),
                36 => 
                array (
                  'variable' => 'forUpdate',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 68,
                ),
                37 => 
                array (
                  'variable' => 'distinct',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 606,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 607,
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
                  'variable' => 'noPrimary',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 607,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 609,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 609,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 609,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 609,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 609,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 610,
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
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 610,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 610,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 610,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 610,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Di',
                        'dynamic' => 0,
                        'name' => 'getDefault',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 611,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 611,
                      'char' => 45,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'container',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 612,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 612,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 613,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 615,
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
                  'variable' => 'models',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 615,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'models',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 615,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 615,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 615,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 616,
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
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 616,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 616,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 616,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 616,
                'char' => 35,
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
                              'value' => 'models',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 617,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 617,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 617,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 617,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 617,
                    'char' => 40,
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
                              'value' => 'At least one model is required to build the query',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 620,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 620,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 620,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 621,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 622,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                        'type' => 'variable',
                        'value' => 'models',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 623,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 623,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 623,
                    'char' => 33,
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
                              'value' => 'At least one model is required to build the query',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 626,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 626,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 626,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 627,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 628,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 630,
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
                  'operator' => 'assign',
                  'variable' => 'conditions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 630,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 630,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 630,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 630,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 632,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_numeric',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 632,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 632,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 632,
                'char' => 35,
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
                        'value' => 'models',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 637,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 637,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 637,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 637,
                    'char' => 39,
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
                                  'value' => 'models',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 638,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 638,
                                'char' => 41,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 638,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 638,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 638,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 638,
                        'char' => 47,
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
                                  'value' => 'Cannot build the query. Invalid condition',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 641,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 641,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 641,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 642,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 644,
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
                          'variable' => 'model',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'models',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 644,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 644,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 644,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 644,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 645,
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
                          'variable' => 'model',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'models',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 646,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 646,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 647,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 653,
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
                      'variable' => 'metaData',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 653,
                          'char' => 38,
                        ),
                        'name' => 'getShared',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'modelsMetadata',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 653,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 653,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 653,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 653,
                      'char' => 64,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'modelInstance',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'model',
                        'dynamic' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 654,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 654,
                            'char' => 49,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 654,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 654,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 654,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 654,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 656,
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
                      'variable' => 'noPrimary',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 656,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 656,
                      'char' => 33,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'primaryKeys',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 657,
                          'char' => 40,
                        ),
                        'name' => 'getPrimaryKeyAttributes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'modelInstance',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 657,
                              'char' => 78,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 657,
                            'char' => 78,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 657,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 657,
                      'char' => 79,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 659,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
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
                          'value' => 'primaryKeys',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 659,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 659,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 659,
                    'char' => 35,
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
                          'value' => 'firstPrimaryKey',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 660,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'primaryKeys',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 660,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 660,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 660,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 660,
                        'char' => 58,
                      ),
                      'statements' => 
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
                                  'value' => 'orm.column_renaming',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 665,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 665,
                                'char' => 55,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 665,
                            'char' => 57,
                          ),
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
                                  'variable' => 'columnMap',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'metaData',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 666,
                                      'char' => 50,
                                    ),
                                    'name' => 'getColumnMap',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'modelInstance',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 666,
                                          'char' => 77,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 666,
                                        'char' => 77,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 666,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 666,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 667,
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
                                  'variable' => 'columnMap',
                                  'expr' => 
                                  array (
                                    'type' => 'null',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 668,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 668,
                                  'char' => 45,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 669,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 671,
                          'char' => 22,
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
                                'value' => 'columnMap',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 671,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 671,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 671,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 671,
                            'char' => 50,
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
                                    'type' => 'fetch',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'attributeField',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 672,
                                      'char' => 87,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'columnMap',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 672,
                                        'char' => 69,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'firstPrimaryKey',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 672,
                                        'char' => 85,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 672,
                                      'char' => 87,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 672,
                                    'char' => 87,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 672,
                                  'char' => 87,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 672,
                                'char' => 87,
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
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'Column \'',
                                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                              'line' => 674,
                                              'char' => 42,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'firstPrimaryKey',
                                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                              'line' => 674,
                                              'char' => 60,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 674,
                                            'char' => 60,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\' isn\'t part of the column map',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 675,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 675,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 675,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 675,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 676,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 677,
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
                                  'variable' => 'attributeField',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'firstPrimaryKey',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 678,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 678,
                                  'char' => 61,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 679,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 681,
                          'char' => 23,
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
                              'variable' => 'conditions',
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
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 681,
                                          'char' => 43,
                                        ),
                                        'name' => 'autoescape',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'model',
                                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                              'line' => 681,
                                              'char' => 60,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 681,
                                            'char' => 60,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 681,
                                        'char' => 62,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '.',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 681,
                                        'char' => 66,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 681,
                                      'char' => 66,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 681,
                                        'char' => 73,
                                      ),
                                      'name' => 'autoescape',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'attributeField',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 681,
                                            'char' => 99,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 681,
                                          'char' => 99,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 681,
                                      'char' => 101,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 681,
                                    'char' => 101,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' = ',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 681,
                                    'char' => 107,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 681,
                                  'char' => 107,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'conditions',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 681,
                                  'char' => 119,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 681,
                                'char' => 119,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 681,
                              'char' => 119,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'noPrimary',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 682,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 682,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 683,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 684,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 689,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noPrimary',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 689,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 689,
                    'char' => 35,
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
                              'value' => 'Source related to this model does not have a primary key defined',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 692,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 692,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 692,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 693,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 694,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 696,
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
                  'variable' => 'distinct',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 696,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'distinct',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 696,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 696,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 696,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 698,
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
                    'value' => 'distinct',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 698,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 698,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 698,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 698,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'distinct',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 699,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'SELECT DISTINCT ',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 700,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 700,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 701,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'SELECT ALL ',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 702,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 702,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 703,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 704,
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
                      'variable' => 'phql',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'SELECT ',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 705,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 705,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 706,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 708,
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
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 708,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 708,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 708,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 708,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 710,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 710,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 710,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 710,
                'char' => 29,
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
                        'value' => 'columns',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 714,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 714,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 714,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 714,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'selectedColumns',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 715,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 715,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 717,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 717,
                        'char' => 52,
                      ),
                      'key' => 'columnAlias',
                      'value' => 'column',
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
                                'value' => 'columnAlias',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 718,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 718,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'integer',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 718,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 718,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'selectedColumns',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'column',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 719,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 719,
                                  'char' => 55,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 720,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'selectedColumns',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'column',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 721,
                                        'char' => 56,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ' AS ',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 721,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 721,
                                      'char' => 63,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 721,
                                        'char' => 70,
                                      ),
                                      'name' => 'autoescape',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'columnAlias',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 721,
                                            'char' => 93,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 721,
                                          'char' => 93,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 721,
                                      'char' => 94,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 721,
                                    'char' => 94,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 721,
                                  'char' => 94,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 722,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 723,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 725,
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
                          'variable' => 'phql',
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
                                  'value' => ', ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 725,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 725,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'selectedColumns',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 725,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 725,
                                'char' => 52,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 725,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 725,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 726,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columns',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 727,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 727,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 728,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 729,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                        'value' => 'models',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 733,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 733,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 733,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 733,
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
                          'variable' => 'selectedColumns',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 734,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 734,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 736,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'models',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 736,
                        'char' => 55,
                      ),
                      'key' => 'modelColumnAlias',
                      'value' => 'model',
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
                                'value' => 'modelColumnAlias',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 737,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 737,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'integer',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 737,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 737,
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
                                  'operator' => 'assign',
                                  'variable' => 'selectedColumn',
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
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 738,
                                        'char' => 51,
                                      ),
                                      'name' => 'autoescape',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'model',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 738,
                                            'char' => 68,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 738,
                                          'char' => 68,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 738,
                                      'char' => 70,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '.*',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 738,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 738,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 738,
                                  'char' => 74,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 739,
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
                                  'variable' => 'selectedColumn',
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
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 740,
                                        'char' => 51,
                                      ),
                                      'name' => 'autoescape',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'modelColumnAlias',
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 740,
                                            'char' => 79,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 740,
                                          'char' => 79,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 740,
                                      'char' => 81,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '.*',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 740,
                                      'char' => 85,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 740,
                                    'char' => 85,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 740,
                                  'char' => 85,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 741,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 743,
                          'char' => 23,
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
                              'variable' => 'selectedColumns',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'selectedColumn',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 743,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 743,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 744,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 746,
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
                          'variable' => 'phql',
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
                                  'value' => ', ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 746,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 746,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'selectedColumns',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 746,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 746,
                                'char' => 52,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 746,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 746,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 747,
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
                          'variable' => 'phql',
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
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 748,
                                'char' => 33,
                              ),
                              'name' => 'autoescape',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'models',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 748,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 748,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 748,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '.*',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 748,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 748,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 748,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 749,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 750,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 755,
              'char' => 10,
            ),
            12 => 
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
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 755,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 755,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 755,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 755,
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
                      'variable' => 'selectedModels',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 756,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 756,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 758,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'models',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 758,
                    'char' => 45,
                  ),
                  'key' => 'modelAlias',
                  'value' => 'model',
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
                            'value' => 'modelAlias',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 759,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 759,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 759,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 759,
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
                              'variable' => 'selectedModel',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 760,
                                      'char' => 46,
                                    ),
                                    'name' => 'autoescape',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'model',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 760,
                                          'char' => 63,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 760,
                                        'char' => 63,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 760,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' AS ',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 760,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 760,
                                  'char' => 72,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 760,
                                    'char' => 79,
                                  ),
                                  'name' => 'autoescape',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'modelAlias',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 760,
                                        'char' => 101,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 760,
                                      'char' => 101,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 760,
                                  'char' => 102,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 760,
                                'char' => 102,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 760,
                              'char' => 102,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 761,
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
                              'variable' => 'selectedModel',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 762,
                                  'char' => 46,
                                ),
                                'name' => 'autoescape',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'model',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 762,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 762,
                                    'char' => 63,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 762,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 762,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 763,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 765,
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
                          'variable' => 'selectedModels',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'selectedModel',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 765,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 765,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 766,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 768,
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
                      'operator' => 'concat-assign',
                      'variable' => 'phql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' FROM ',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 768,
                          'char' => 31,
                        ),
                        'right' => 
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
                                'value' => ', ',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 768,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 768,
                              'char' => 40,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'selectedModels',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 768,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 768,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 768,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 768,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 768,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 769,
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
                      'variable' => 'phql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' FROM ',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 770,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 770,
                            'char' => 38,
                          ),
                          'name' => 'autoescape',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'models',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 770,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 770,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 770,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 770,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 770,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 771,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 776,
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
                  'variable' => 'joins',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 776,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'joins',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 776,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 776,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 776,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 778,
              'char' => 10,
            ),
            14 => 
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
                    'value' => 'joins',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 778,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 778,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 778,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 778,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'joins',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 779,
                    'char' => 31,
                  ),
                  'value' => 'join',
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
                          'variable' => 'joinModel',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 783,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 783,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 783,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 783,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 788,
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
                          'variable' => 'joinConditions',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 788,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 788,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 788,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 788,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 793,
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
                          'variable' => 'joinAlias',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 793,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 793,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 793,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 793,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 798,
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
                          'variable' => 'joinType',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 798,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '3',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 798,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 798,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 798,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 803,
                      'char' => 18,
                    ),
                    4 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'joinType',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 803,
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
                              'variable' => 'phql',
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
                                      'value' => ' ',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 804,
                                      'char' => 34,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'joinType',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 804,
                                      'char' => 45,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 804,
                                    'char' => 45,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' JOIN ',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 804,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 804,
                                  'char' => 54,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 804,
                                    'char' => 61,
                                  ),
                                  'name' => 'autoescape',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'joinModel',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 804,
                                        'char' => 82,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 804,
                                      'char' => 82,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 804,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 804,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 804,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 805,
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
                              'variable' => 'phql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' JOIN ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 806,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 806,
                                    'char' => 46,
                                  ),
                                  'name' => 'autoescape',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'joinModel',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 806,
                                        'char' => 67,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 806,
                                      'char' => 67,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 806,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 806,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 806,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 807,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 812,
                      'char' => 18,
                    ),
                    5 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'joinAlias',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 812,
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
                              'variable' => 'phql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' AS ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 813,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 813,
                                    'char' => 44,
                                  ),
                                  'name' => 'autoescape',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'joinAlias',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 813,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 813,
                                      'char' => 65,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 813,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 813,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 813,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 814,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 819,
                      'char' => 18,
                    ),
                    6 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'joinConditions',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 819,
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
                              'variable' => 'phql',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ON ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 820,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'joinConditions',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 820,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 820,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 820,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 821,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 822,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 823,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 826,
              'char' => 10,
            ),
            15 => 
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
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 826,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 826,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 826,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 826,
                'char' => 40,
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
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'conditions',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 827,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 827,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 827,
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
                          'operator' => 'concat-assign',
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' WHERE ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 828,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'conditions',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 828,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 828,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 828,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 829,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 830,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 835,
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
                  'variable' => 'group',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 835,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 835,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 835,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 835,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 836,
              'char' => 10,
            ),
            17 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'group',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 836,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 836,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 836,
                'char' => 27,
              ),
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
                      'variable' => 'groupItems',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 837,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 837,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 839,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 839,
                    'char' => 36,
                  ),
                  'value' => 'groupItem',
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
                          'variable' => 'groupItems',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 840,
                              'char' => 41,
                            ),
                            'name' => 'autoescape',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'groupItem',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 840,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 840,
                                'char' => 62,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 840,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 840,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 841,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 843,
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
                      'operator' => 'concat-assign',
                      'variable' => 'phql',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' GROUP BY ',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 843,
                          'char' => 35,
                        ),
                        'right' => 
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
                                'value' => ', ',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 843,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 843,
                              'char' => 44,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'groupItems',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 843,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 843,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 843,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 843,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 843,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 844,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 849,
              'char' => 11,
            ),
            18 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'having',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 849,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 849,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 849,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 849,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 850,
              'char' => 10,
            ),
            19 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'having',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 850,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 850,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 850,
                'char' => 28,
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
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'having',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 851,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 851,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 851,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' HAVING ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 852,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'having',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 852,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 852,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 852,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 853,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 854,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 859,
              'char' => 11,
            ),
            20 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'order',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 859,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'order',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 859,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 859,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 859,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 861,
              'char' => 10,
            ),
            21 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'order',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 861,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 861,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 861,
                'char' => 27,
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
                        'value' => 'order',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 862,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 862,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 862,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 862,
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
                          'variable' => 'orderItems',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 863,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 863,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 865,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'order',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 865,
                        'char' => 40,
                      ),
                      'value' => 'orderItem',
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
                                'value' => 'orderItem',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 869,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 869,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'integer',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 869,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 869,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'orderItems',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'orderItem',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 870,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 870,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 872,
                              'char' => 32,
                            ),
                            1 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 873,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 875,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'not-identical',
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
                                    'value' => 'orderItem',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 875,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 875,
                                  'char' => 40,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' ',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 875,
                                    'char' => 43,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 875,
                                  'char' => 43,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 875,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 875,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 875,
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
                                  'variable' => 'itemExplode',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 876,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 878,
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
                                  'variable' => 'itemExplode',
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
                                          'value' => ' ',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 878,
                                          'char' => 52,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 878,
                                        'char' => 52,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'orderItem',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 878,
                                          'char' => 63,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 878,
                                        'char' => 63,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 878,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 878,
                                  'char' => 64,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 879,
                              'char' => 27,
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
                                  'variable' => 'orderItems',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                          'line' => 879,
                                          'char' => 49,
                                        ),
                                        'name' => 'autoescape',
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
                                                'value' => 'itemExplode',
                                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                                'line' => 879,
                                                'char' => 72,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'int',
                                                'value' => '0',
                                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                                'line' => 879,
                                                'char' => 74,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                              'line' => 879,
                                              'char' => 75,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                            'line' => 879,
                                            'char' => 75,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 879,
                                        'char' => 77,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ' ',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 879,
                                        'char' => 81,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 879,
                                      'char' => 81,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'itemExplode',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 879,
                                        'char' => 94,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 879,
                                        'char' => 96,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 879,
                                      'char' => 97,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 879,
                                    'char' => 97,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 879,
                                  'char' => 97,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 881,
                              'char' => 32,
                            ),
                            3 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 882,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 884,
                          'char' => 23,
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
                              'variable' => 'orderItems',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 884,
                                  'char' => 45,
                                ),
                                'name' => 'autoescape',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'orderItem',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 884,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 884,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 884,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 884,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 885,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 887,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' ORDER BY ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 887,
                              'char' => 39,
                            ),
                            'right' => 
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
                                    'value' => ', ',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 887,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 887,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'orderItems',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 887,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 887,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 887,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 887,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 887,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 888,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => ' ORDER BY ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 889,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'order',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 889,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 889,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 889,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 890,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 891,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 896,
              'char' => 11,
            ),
            22 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'limit',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 896,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'limit',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 896,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 896,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 896,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 897,
              'char' => 10,
            ),
            23 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'limit',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 897,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 897,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 897,
                'char' => 27,
              ),
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
                      'variable' => 'number',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 898,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 898,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 900,
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
                        'value' => 'limit',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 900,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 900,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 900,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 900,
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
                          'variable' => 'number',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'limit',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 901,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'number',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 901,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 901,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 901,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 903,
                      'char' => 18,
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
                          'value' => 'offset',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 903,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'limit',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 903,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'offset',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 903,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 903,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 903,
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
                              'type' => 'fcall',
                              'name' => 'is_numeric',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'offset',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 904,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 904,
                                  'char' => 42,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 904,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 904,
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
                                  'variable' => 'offset',
                                  'expr' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 905,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 905,
                                  'char' => 39,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 906,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 907,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 908,
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
                        'type' => 'fcall',
                        'name' => 'is_numeric',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'limit',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 909,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 909,
                            'char' => 36,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 909,
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
                              'variable' => 'number',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'limit',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 910,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 910,
                              'char' => 39,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'offset',
                              'expr' => 
                              array (
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 911,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'offset',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 911,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 911,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 911,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 912,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'not-identical',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'offset',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 912,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 912,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 912,
                            'char' => 40,
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
                                  'type' => 'fcall',
                                  'name' => 'is_numeric',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'offset',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 913,
                                        'char' => 46,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 913,
                                      'char' => 46,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 913,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 913,
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
                                      'variable' => 'offset',
                                      'expr' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                        'line' => 914,
                                        'char' => 43,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 914,
                                      'char' => 43,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 915,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 916,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 917,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 918,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 920,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_numeric',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'number',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 920,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 920,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 920,
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
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' LIMIT :APL0:',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 921,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 921,
                          'char' => 41,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'APL0',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 922,
                              'char' => 42,
                            ),
                          ),
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
                                  'value' => 'number',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 922,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 922,
                                'char' => 59,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '10',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 922,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 922,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 922,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 922,
                          'char' => 64,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'APL0',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 923,
                              'char' => 41,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'Column',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 923,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'BIND_PARAM_INT',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 923,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 923,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 923,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 925,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'is_numeric',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'offset',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 925,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 925,
                              'char' => 37,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 925,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'offset',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 925,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 925,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 925,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 925,
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
                              'operator' => 'concat-assign',
                              'variable' => 'phql',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => ' OFFSET :APL1:',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 926,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 926,
                              'char' => 46,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'bindParams',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'APL1',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 927,
                                  'char' => 46,
                                ),
                              ),
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
                                      'value' => 'offset',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 927,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 927,
                                    'char' => 63,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '10',
                                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                      'line' => 927,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                    'line' => 927,
                                    'char' => 67,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 927,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 927,
                              'char' => 68,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'bindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'APL1',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 928,
                                  'char' => 45,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 928,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 928,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 928,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 928,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 929,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 930,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 931,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 933,
              'char' => 11,
            ),
            24 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'forUpdate',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 933,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'forUpdate',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 933,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 933,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 933,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 935,
              'char' => 10,
            ),
            25 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'forUpdate',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 935,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 935,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 935,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 935,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'forUpdate',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 936,
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
                          'operator' => 'concat-assign',
                          'variable' => 'phql',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' FOR UPDATE',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 937,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 937,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 938,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 939,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 941,
              'char' => 14,
            ),
            26 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'phql',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 941,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 942,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a PHQL statement built based on the builder parameters
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 599,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 599,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 598,
          'last-line' => 946,
          'char' => 25,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getQuery',
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
                  'variable' => 'query',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 949,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 949,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'bindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 949,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'phql',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 949,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 949,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 951,
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
                  'variable' => 'phql',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 951,
                      'char' => 25,
                    ),
                    'name' => 'getPhql',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 951,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 951,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 953,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 953,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 953,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 953,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 953,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 953,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 953,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 955,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 955,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 955,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 955,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 955,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 955,
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
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Exception',
                          'dynamic' => 0,
                          'name' => 'containerServiceNotFound',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'the services related to the ORM',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 959,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 959,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 960,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 960,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 960,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 961,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 966,
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
                  'variable' => 'query',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'QueryInterface',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 969,
                      'char' => 10,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 966,
                        'char' => 48,
                      ),
                      'name' => 'get',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'Phalcon\\\\Mvc\\\\Model\\\\Query',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 967,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 967,
                          'char' => 39,
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
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'phql',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 968,
                                  'char' => 18,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 968,
                                'char' => 18,
                              ),
                              1 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'container',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 968,
                                  'char' => 29,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 968,
                                'char' => 29,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 969,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 969,
                          'char' => 9,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 969,
                      'char' => 10,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 969,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 969,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 972,
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
                  'variable' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 972,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 972,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 972,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 972,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 973,
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
                    'value' => 'bindParams',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 973,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 973,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 973,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 973,
                'char' => 39,
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
                      'value' => 'query',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 974,
                      'char' => 19,
                    ),
                    'name' => 'setBindParams',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 974,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 974,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 974,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 975,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 978,
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
                  'variable' => 'bindTypes',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 978,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 978,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 978,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 978,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 979,
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
                    'value' => 'bindTypes',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 979,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 979,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 979,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 979,
                'char' => 38,
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
                      'value' => 'query',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 980,
                      'char' => 19,
                    ),
                    'name' => 'setBindTypes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindTypes',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 980,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 980,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 980,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 981,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 983,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 983,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sharedLock',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 983,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 983,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 983,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 983,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 983,
                'char' => 48,
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
                      'value' => 'query',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 984,
                      'char' => 19,
                    ),
                    'name' => 'setSharedLock',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 984,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sharedLock',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 984,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 984,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 984,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 984,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 985,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 987,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'query',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 987,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 988,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the query built
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 948,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 948,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 948,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 947,
          'last-line' => 994,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWhere',
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 997,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'conditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 997,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 997,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 998,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the conditions for the query
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 995,
          'last-line' => 1012,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'groupBy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'group',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1013,
              'char' => 38,
            ),
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
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1015,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1015,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1015,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1015,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
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
                          'value' => 'group',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1016,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1016,
                        'char' => 28,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => ',',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1016,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1016,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1016,
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
                          'variable' => 'group',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 1017,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1017,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 1017,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1017,
                                'char' => 44,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'group',
                                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                  'line' => 1017,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1017,
                                'char' => 51,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1017,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1017,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1018,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1020,
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
                      'variable' => 'group',
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
                              'value' => ',',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1020,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1020,
                            'char' => 34,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'group',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1020,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1020,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1020,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1020,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1021,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1023,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'group',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1023,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1023,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1025,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1025,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1026,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a GROUP BY clause
     *
     *```php
     * $builder->groupBy(
     *     [
     *         "Robots.name",
     *     ]
     * );
     *```
     *
     * @param string|array group
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1014,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1014,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1014,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1013,
          'last-line' => 1041,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'having',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1042,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1042,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1042,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1042,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1042,
              'char' => 87,
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
                  'variable' => 'currentBindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1044,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'currentBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1044,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1046,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'having',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1046,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1046,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1048,
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
                  'variable' => 'currentBindParams',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1048,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1048,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1048,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1048,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1053,
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
                    'value' => 'currentBindParams',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1053,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1053,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1053,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1053,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindParams',
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'currentBindParams',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1054,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1054,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1054,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1054,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1055,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindParams',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1056,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1056,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1057,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1059,
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
                  'variable' => 'currentBindTypes',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1059,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1059,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1059,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1059,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1064,
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
                    'value' => 'currentBindTypes',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1064,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1064,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1064,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1064,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindTypes',
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'currentBindTypes',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1065,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindTypes',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1065,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1065,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1065,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1066,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindTypes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1067,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1067,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1068,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1070,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1070,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1071,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the HAVING condition clause
     *
     *```php
     * $builder->having("SUM(Robots.price) > 0");
     *
     * $builder->having(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1043,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1043,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1043,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1042,
          'last-line' => 1079,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1080,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1080,
              'char' => 57,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1080,
                  'char' => 108,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1080,
                  'char' => 108,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1080,
                'char' => 108,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1080,
              'char' => 108,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1082,
                  'char' => 21,
                ),
                'name' => 'conditionIn',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1082,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1082,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1082,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1082,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1082,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1082,
                    'char' => 56,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1082,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1082,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1082,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1083,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->inHaving("SUM(Robots.price)", [100, 200]);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1081,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1081,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1081,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1080,
          'last-line' => 1107,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'innerJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1108,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1108,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1108,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1108,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1108,
              'char' => 91,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'joins',
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1110,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1110,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1110,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1110,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1110,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1110,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'INNER',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1110,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1110,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1110,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1110,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1112,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1112,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1113,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an INNER join to the query
     *
     *```php
     * // Inner Join model \'Robots\' with automatic conditions and alias
     * $builder->innerJoin(
     *     Robots::class
     * );
     *
     * // Inner Join model \'Robots\' specifying conditions
     * $builder->innerJoin(
     *     Robots::class,
     *     "Robots.id = RobotsParts.robots_id"
     * );
     *
     * // Inner Join model \'Robots\' specifying conditions and alias
     * $builder->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1109,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1108,
          'last-line' => 1124,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1125,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1125,
              'char' => 56,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1125,
                  'char' => 107,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1125,
                  'char' => 107,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1125,
                'char' => 107,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1125,
              'char' => 107,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1127,
                  'char' => 21,
                ),
                'name' => 'conditionIn',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Where',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1127,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1127,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1127,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1127,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1127,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1127,
                    'char' => 55,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1127,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1127,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1127,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1128,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition to the current WHERE conditions
     *
     *```php
     * $builder->inWhere(
     *     "id",
     *     [1, 2, 3]
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1126,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1126,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1126,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1125,
          'last-line' => 1160,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'join',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1161,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1161,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1161,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1161,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1161,
              'char' => 86,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1161,
                'char' => 106,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1161,
              'char' => 106,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'joins',
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1163,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1163,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1163,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1163,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1163,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1163,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1163,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1163,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1163,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1163,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1165,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1165,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1166,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an :type: join (by default type - INNER) to the query
     *
     *```php
     * // Inner Join model \'Robots\' with automatic conditions and alias
     * $builder->join(
     *     Robots::class
     * );
     *
     * // Inner Join model \'Robots\' specifying conditions
     * $builder->join(
     *     Robots::class,
     *     "Robots.id = RobotsParts.robots_id"
     * );
     *
     * // Inner Join model \'Robots\' specifying conditions and alias
     * $builder->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *
     * // Left Join model \'Robots\' specifying conditions, alias and type of join
     * $builder->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r",
     *     "LEFT"
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1162,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1162,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1162,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1161,
          'last-line' => 1178,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'leftJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1179,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1179,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1179,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1179,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1179,
              'char' => 90,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'joins',
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1181,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1181,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1181,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1181,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1181,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1181,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'LEFT',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1181,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1181,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1181,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1181,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1183,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1183,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1184,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a LEFT join to the query
     *
     *```php
     * $builder->leftJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1180,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1180,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1180,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1179,
          'last-line' => 1194,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'limit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'limit',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1195,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1195,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1195,
              'char' => 55,
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'limit',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'abs',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'limit',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1197,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1197,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1197,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1197,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1199,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'limit',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1199,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1199,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1199,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1199,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1200,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1201,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1203,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'limit',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'limit',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1203,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1203,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1205,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_numeric',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'offset',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1205,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1205,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1205,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'offset',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'abs',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'cast',
                              'left' => 'int',
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'offset',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1206,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1206,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1206,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1206,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1206,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1207,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1209,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1209,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1210,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a LIMIT clause, optionally an offset clause
     *
     * ```php
     * $builder->limit(100);
     * $builder->limit(100, 20);
     * $builder->limit("100", "20");
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1196,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1196,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1196,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1195,
          'last-line' => 1218,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notBetweenHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1219,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1219,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1219,
              'char' => 76,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1219,
                  'char' => 127,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1219,
                  'char' => 127,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1219,
                'char' => 127,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1219,
              'char' => 127,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1221,
                  'char' => 21,
                ),
                'name' => 'conditionNotBetween',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1222,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1222,
                    'char' => 19,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1223,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1223,
                    'char' => 21,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1224,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1224,
                    'char' => 17,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'minimum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1225,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1225,
                    'char' => 20,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'maximum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1227,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1227,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1227,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1228,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1220,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1220,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1220,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1219,
          'last-line' => 1236,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notBetweenWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1237,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1237,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1237,
              'char' => 75,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1237,
                  'char' => 126,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1237,
                  'char' => 126,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1237,
                'char' => 126,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1237,
              'char' => 126,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1239,
                  'char' => 21,
                ),
                'name' => 'conditionNotBetween',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Where',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1240,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1240,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1241,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1241,
                    'char' => 21,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1242,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1242,
                    'char' => 17,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'minimum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1243,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1243,
                    'char' => 20,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'maximum',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1245,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1245,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1245,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1246,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition to the current WHERE conditions
     *
     *```php
     * $builder->notBetweenWhere("price", 100.25, 200.50);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1238,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1238,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1238,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1237,
          'last-line' => 1254,
          'char' => 19,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notInHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1255,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1255,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1255,
                  'char' => 111,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1255,
                  'char' => 111,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1255,
                'char' => 111,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1255,
              'char' => 111,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1257,
                  'char' => 21,
                ),
                'name' => 'conditionNotIn',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1257,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1257,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1257,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1257,
                    'char' => 53,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1257,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1257,
                    'char' => 59,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1257,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1257,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1257,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1258,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->notInHaving("SUM(Robots.price)", [100, 200]);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1256,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1256,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1256,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1255,
          'last-line' => 1266,
          'char' => 19,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notInWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1267,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1267,
              'char' => 59,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1267,
                  'char' => 110,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1267,
                  'char' => 110,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1267,
                'char' => 110,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1267,
              'char' => 110,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1269,
                  'char' => 21,
                ),
                'name' => 'conditionNotIn',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Where',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1269,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1269,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1269,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1269,
                    'char' => 52,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1269,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1269,
                    'char' => 58,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1269,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1269,
                    'char' => 66,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1269,
                'char' => 67,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1270,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition to the current WHERE conditions
     *
     *```php
     * $builder->notInWhere("id", [1, 2, 3]);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1268,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1268,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1268,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1267,
          'last-line' => 1278,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1279,
              'char' => 38,
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
                  'property' => 'offset',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'offset',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1281,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1281,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1283,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1283,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1284,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an OFFSET clause
     *
     *```php
     * $builder->offset(30);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1280,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1280,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1280,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1279,
          'last-line' => 1296,
          'char' => 19,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'orderBy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'orderBy',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1297,
              'char' => 40,
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
                  'property' => 'order',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'orderBy',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1299,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1299,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1301,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1301,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1302,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an ORDER BY condition clause
     *
     *```php
     * $builder->orderBy("Robots.name");
     * $builder->orderBy(["1", "Robots.name"]);
     * $builder->orderBy(["Robots.name DESC"]);
     *```
     *
     * @param string|array orderBy
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1298,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1298,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1298,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1297,
          'last-line' => 1317,
          'char' => 19,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'orHaving',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1318,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1318,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1318,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1318,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1318,
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
                  'variable' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1320,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1322,
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
                  'variable' => 'currentConditions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1322,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'having',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1322,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1322,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1322,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1327,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'currentConditions',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1327,
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
                      'operator' => 'assign',
                      'variable' => 'conditions',
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
                                'value' => '(',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1328,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1328,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1328,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') OR (',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1328,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1328,
                            'char' => 61,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1328,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1328,
                          'char' => 74,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1328,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1328,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1328,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1331,
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1331,
                  'char' => 21,
                ),
                'name' => 'having',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1331,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1331,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1331,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1331,
                    'char' => 51,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1331,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1331,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1331,
                'char' => 63,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1332,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current HAVING conditions clause using an OR operator
     *
     *```php
     * $builder->orHaving("SUM(Robots.price) > 0");
     *
     * $builder->orHaving(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1319,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1319,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1319,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1318,
          'last-line' => 1348,
          'char' => 19,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'orWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1349,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1349,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1349,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1349,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1349,
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
                  'variable' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1351,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1353,
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
                  'variable' => 'currentConditions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1353,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1353,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1353,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1353,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1358,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'currentConditions',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1358,
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
                      'operator' => 'assign',
                      'variable' => 'conditions',
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
                                'value' => '(',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1359,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1359,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1359,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') OR (',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1359,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1359,
                            'char' => 61,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1359,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1359,
                          'char' => 74,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1359,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1359,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1359,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1360,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1362,
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1362,
                  'char' => 21,
                ),
                'name' => 'where',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1362,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1362,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1362,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1362,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1362,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1362,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1362,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1363,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an OR operator
     *
     *```php
     * $builder->orWhere("name = \'Peter\'");
     *
     * $builder->orWhere(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1350,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1350,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1350,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1349,
          'last-line' => 1375,
          'char' => 19,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rightJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1376,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1376,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1376,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1376,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1376,
              'char' => 91,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'joins',
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1378,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1378,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1378,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1378,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1378,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1378,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'RIGHT',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1378,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1378,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1378,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1378,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1380,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1380,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1381,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a RIGHT join to the query
     *
     *```php
     * $builder->rightJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1377,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1377,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1377,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1376,
          'last-line' => 1385,
          'char' => 19,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBindParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1386,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1386,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1386,
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
                  'variable' => 'currentBindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1388,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1390,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'merge',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1390,
                'char' => 18,
              ),
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
                      'variable' => 'currentBindParams',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1391,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1391,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1391,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1391,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1392,
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
                        'value' => 'currentBindParams',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1392,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1392,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1392,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1392,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'currentBindParams',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1393,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'bindParams',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1393,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1393,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1393,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1394,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindParams',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1395,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1395,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1396,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1397,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindParams',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1398,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1398,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1399,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1401,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1401,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1402,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set default bind parameters
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1387,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1387,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1387,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1386,
          'last-line' => 1406,
          'char' => 19,
        ),
        45 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBindTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1407,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1407,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1407,
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
                  'variable' => 'currentBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1409,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1411,
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
                  'type' => 'variable',
                  'value' => 'merge',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1411,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1411,
                'char' => 27,
              ),
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
                      'variable' => 'currentBindTypes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1412,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindTypes',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1412,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1412,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1412,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1414,
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
                        'value' => 'currentBindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1414,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1414,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1414,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1414,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'currentBindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1415,
                              'char' => 56,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'bindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1415,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1415,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1415,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1416,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindTypes',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1417,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1417,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1418,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1419,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'bindTypes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1420,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1420,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1421,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1423,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1423,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1424,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set default bind types
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1408,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1408,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1408,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1407,
          'last-line' => 1428,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
          'parameters' => 
          array (
            0 => 
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
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1429,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1429,
              'char' => 50,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1431,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1431,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1433,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1433,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1434,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjector container
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1430,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1430,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1430,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1429,
          'last-line' => 1452,
          'char' => 19,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'where',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1453,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1453,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1453,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1453,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1453,
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
                  'variable' => 'currentBindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1455,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'currentBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1455,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1457,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'conditions',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1457,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1457,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1462,
              'char' => 10,
            ),
            2 => 
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
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1462,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1462,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1462,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1462,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1462,
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
                      'variable' => 'currentBindParams',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1463,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1463,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1463,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1463,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1465,
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
                        'value' => 'currentBindParams',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1465,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1465,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1465,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1465,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'currentBindParams',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1466,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'bindParams',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1466,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1466,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1466,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1467,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindParams',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindParams',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1468,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1468,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1469,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1470,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1475,
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
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1475,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1475,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1475,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1475,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1475,
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
                      'variable' => 'currentBindTypes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1476,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindTypes',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1476,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1476,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1476,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1478,
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
                        'value' => 'currentBindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1478,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1478,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1478,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1478,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'currentBindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1479,
                              'char' => 56,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'bindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1479,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1479,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1479,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1480,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'bindTypes',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindTypes',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1481,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1481,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1482,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1483,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1485,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1485,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1486,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the query WHERE conditions
     *
     *```php
     * $builder->where(100);
     *
     * $builder->where("name = \'Peter\'");
     *
     * $builder->where(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1454,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1454,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1454,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1453,
          'last-line' => 1490,
          'char' => 19,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'conditionBetween',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'clause',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1491,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1491,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1491,
              'char' => 87,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1491,
              'char' => 100,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1491,
              'char' => 113,
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
                  'variable' => 'hiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1493,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1493,
                  'char' => 41,
                ),
                2 => 
                array (
                  'variable' => 'minimumKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1493,
                  'char' => 53,
                ),
                3 => 
                array (
                  'variable' => 'maximumKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1493,
                  'char' => 65,
                ),
                4 => 
                array (
                  'variable' => 'operatorMethod',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1493,
                  'char' => 81,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1495,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1495,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1495,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_AND',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1495,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1495,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1495,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1495,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1495,
                          'char' => 93,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_OR',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1495,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1495,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1495,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1495,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1495,
                  'char' => 95,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1495,
                'char' => 95,
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
                          'type' => 'fcall',
                          'name' => 'sprintf',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'Operator % is not available.',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1498,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1498,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'operator',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1500,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1500,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1501,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1501,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1501,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1502,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1504,
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
                  'variable' => 'operatorMethod',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1504,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1504,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1504,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1504,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1506,
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
                  'variable' => 'hiddenParam',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1506,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1506,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1506,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1506,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'nextHiddenParam',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1507,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1507,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1507,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1507,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1513,
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
                  'variable' => 'minimumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'AP',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1513,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1513,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1513,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1513,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'maximumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'AP',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1514,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nextHiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1514,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1514,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1514,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1521,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1521,
                  'char' => 14,
                ),
                'name' => 'operatorMethod',
                'call-type' => 2,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'expr',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1522,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' BETWEEN :',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1522,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1522,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'minimumKey',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1522,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1522,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ': AND :',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1522,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1522,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximumKey',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1522,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1522,
                        'char' => 67,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1522,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1522,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1522,
                    'char' => 70,
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
                            'type' => 'variable',
                            'value' => 'minimumKey',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1524,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minimum',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1524,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1524,
                          'char' => 36,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximumKey',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1525,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximum',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1526,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1526,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1527,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1527,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1527,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1529,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'incr',
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1529,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'hiddenParamNumber',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'nextHiddenParam',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1530,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1530,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1532,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1532,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1533,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1492,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1492,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1492,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1491,
          'last-line' => 1537,
          'char' => 22,
        ),
        49 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'conditionIn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'clause',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1538,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1538,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1538,
              'char' => 82,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1538,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'queryKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'bindKeys',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 43,
                ),
                4 => 
                array (
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'operatorMethod',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1540,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1541,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1541,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1543,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1543,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1543,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_AND',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1543,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1543,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1543,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1543,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1543,
                          'char' => 93,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_OR',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1543,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1543,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1543,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1543,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1543,
                  'char' => 95,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1543,
                'char' => 95,
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
                          'type' => 'fcall',
                          'name' => 'sprintf',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'Operator % is not available.',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1546,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1546,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'operator',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1548,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1548,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1549,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1549,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1549,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1550,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1552,
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
                  'variable' => 'operatorMethod',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1552,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1552,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1552,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1552,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1554,
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
                        'value' => 'values',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1554,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1554,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1554,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1554,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1555,
                      'char' => 18,
                    ),
                    'name' => 'operatorMethod',
                    'call-type' => 2,
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
                              'type' => 'variable',
                              'value' => 'expr',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1555,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' != ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1555,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1555,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1555,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1555,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1555,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1555,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1557,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1557,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1558,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1560,
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
                  'variable' => 'hiddenParam',
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
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1560,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hiddenParamNumber',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1560,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1560,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1560,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1560,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1562,
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
                  'operator' => 'assign',
                  'variable' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1562,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1562,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bindKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1563,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1563,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1565,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1565,
                'char' => 29,
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
                      'operator' => 'assign',
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'AP',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1569,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hiddenParam',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1569,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1569,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1569,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'queryKey',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => ':',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1570,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1570,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1570,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1570,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1570,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1570,
                      'char' => 39,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'bindKeys',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'queryKey',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1571,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1571,
                      'char' => 38,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'bindParams',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1572,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1572,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1572,
                      'char' => 40,
                    ),
                    4 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1573,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1574,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1580,
              'char' => 12,
            ),
            8 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1580,
                  'char' => 14,
                ),
                'name' => 'operatorMethod',
                'call-type' => 2,
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
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1581,
                            'char' => 18,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' IN (',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1581,
                            'char' => 26,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1581,
                          'char' => 26,
                        ),
                        'right' => 
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
                                'value' => ', ',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1581,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1581,
                              'char' => 35,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'bindKeys',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1581,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1581,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1581,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1581,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ')',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1581,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1581,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1581,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1583,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1583,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1583,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1585,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'hiddenParamNumber',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hiddenParam',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1585,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1585,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1587,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1587,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1588,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1539,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1539,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1539,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1538,
          'last-line' => 1592,
          'char' => 22,
        ),
        50 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'conditionNotBetween',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'clause',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1593,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1593,
              'char' => 76,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1593,
              'char' => 90,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1593,
              'char' => 103,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1593,
              'char' => 116,
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
                  'variable' => 'hiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1595,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1595,
                  'char' => 41,
                ),
                2 => 
                array (
                  'variable' => 'minimumKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1595,
                  'char' => 53,
                ),
                3 => 
                array (
                  'variable' => 'maximumKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1595,
                  'char' => 65,
                ),
                4 => 
                array (
                  'variable' => 'operatorMethod',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1595,
                  'char' => 81,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1597,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1597,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1597,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_AND',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1597,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1597,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1597,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1597,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1597,
                          'char' => 93,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_OR',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1597,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1597,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1597,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1597,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1597,
                  'char' => 95,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1597,
                'char' => 95,
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
                          'type' => 'fcall',
                          'name' => 'sprintf',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'Operator % is not available.',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1600,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1600,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'operator',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1602,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1602,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1603,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1603,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1603,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1604,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1606,
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
                  'variable' => 'operatorMethod',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1606,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1606,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1606,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1606,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1608,
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
                  'variable' => 'hiddenParam',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1608,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1608,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1608,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1608,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'nextHiddenParam',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1609,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1609,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1609,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1609,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1615,
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
                  'variable' => 'minimumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'AP',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1615,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1615,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1615,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1615,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'maximumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'AP',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1616,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nextHiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1616,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1616,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1616,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1622,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1622,
                  'char' => 14,
                ),
                'name' => 'operatorMethod',
                'call-type' => 2,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'expr',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1623,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' NOT BETWEEN :',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1623,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1623,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'minimumKey',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1623,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1623,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ': AND :',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1623,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1623,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximumKey',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1623,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1623,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1623,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1623,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1623,
                    'char' => 74,
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
                            'type' => 'variable',
                            'value' => 'minimumKey',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1625,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minimum',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1625,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1625,
                          'char' => 36,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximumKey',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1626,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximum',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1627,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1627,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1628,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1628,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1628,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1630,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'incr',
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1630,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'hiddenParamNumber',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'nextHiddenParam',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1631,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1631,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1633,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1633,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1634,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1594,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1594,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1594,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1593,
          'last-line' => 1638,
          'char' => 22,
        ),
        51 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'conditionNotIn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'clause',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1639,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1639,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1639,
              'char' => 85,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1639,
              'char' => 100,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'queryKey',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'bindKeys',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 43,
                ),
                4 => 
                array (
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'operatorMethod',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1641,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1642,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1642,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1644,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1644,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1644,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_AND',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1644,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1644,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1644,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'operator',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1644,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Builder',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1644,
                          'char' => 93,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'OPERATOR_OR',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1644,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1644,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1644,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1644,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1644,
                  'char' => 95,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1644,
                'char' => 95,
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
                          'type' => 'fcall',
                          'name' => 'sprintf',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'Operator % is not available.',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1647,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1647,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'operator',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1649,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1649,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1650,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1650,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1650,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1651,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1653,
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
                  'variable' => 'operatorMethod',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'operator',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1653,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clause',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1653,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1653,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1653,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1655,
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
                        'value' => 'values',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1655,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1655,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1655,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1655,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1656,
                      'char' => 18,
                    ),
                    'name' => 'operatorMethod',
                    'call-type' => 2,
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
                              'type' => 'variable',
                              'value' => 'expr',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1656,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' != ',
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1656,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1656,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1656,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1656,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1656,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1656,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1658,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1658,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1659,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1661,
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
                  'variable' => 'hiddenParam',
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
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1661,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hiddenParamNumber',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1661,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1661,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1661,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1661,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1663,
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
                  'operator' => 'assign',
                  'variable' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1663,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1663,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bindKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1664,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1664,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1666,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1666,
                'char' => 29,
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
                      'operator' => 'assign',
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'AP',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1670,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hiddenParam',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1670,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1670,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1670,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'queryKey',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => ':',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1671,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1671,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1671,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1671,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1671,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1671,
                      'char' => 39,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'bindKeys',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'queryKey',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1672,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1672,
                      'char' => 38,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'bindParams',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1673,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1673,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1673,
                      'char' => 40,
                    ),
                    4 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1674,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1675,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1681,
              'char' => 12,
            ),
            8 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1681,
                  'char' => 14,
                ),
                'name' => 'operatorMethod',
                'call-type' => 2,
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
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1681,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' NOT IN (',
                            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                            'line' => 1681,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1681,
                          'char' => 49,
                        ),
                        'right' => 
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
                                'value' => ', ',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1681,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1681,
                              'char' => 58,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'bindKeys',
                                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                                'line' => 1681,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                              'line' => 1681,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                          'line' => 1681,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1681,
                        'char' => 70,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ')',
                        'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                        'line' => 1681,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1681,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1681,
                    'char' => 73,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                      'line' => 1681,
                      'char' => 85,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1681,
                    'char' => 85,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1681,
                'char' => 86,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1683,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'hiddenParamNumber',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hiddenParam',
                    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                    'line' => 1683,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1683,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1685,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1685,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
              'line' => 1686,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                  'line' => 1640,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
                'line' => 1640,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
            'line' => 1640,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
          'line' => 1639,
          'last-line' => 1687,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
      'line' => 58,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Builder.zep',
    'line' => 58,
    'char' => 5,
  ),
);