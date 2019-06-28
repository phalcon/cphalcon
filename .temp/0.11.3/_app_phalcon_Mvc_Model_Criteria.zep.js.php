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
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 17,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\CriteriaInterface',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 18,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\ResultsetInterface',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 19,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 20,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
    'line' => 38,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Criteria
 *
 * This class is used to build the array parameter required by
 * Phalcon\\Mvc\\Model::find() and Phalcon\\Mvc\\Model::findFirst() using an
 * object-oriented interface.
 *
 * ```php
 * $robots = Robots::query()
 *     ->where("type = :type:")
 *     ->andWhere("year < 2000")
 *     ->bind(["type" => "mechanical"])
 *     ->limit(5, 10)
 *     ->orderBy("name")
 *     ->execute();
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
    'line' => 39,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'Criteria',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CriteriaInterface',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 39,
        'char' => 44,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
        'line' => 40,
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
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 43,
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
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 45,
          'char' => 13,
        ),
        2 => 
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
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 45,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 47,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'model',
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 49,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'params',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 49,
            'char' => 26,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 53,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 54,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 54,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'di',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 56,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 56,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 56,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjector container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 55,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 54,
          'last-line' => 61,
          'char' => 19,
        ),
        1 => 
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
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 64,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 64,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 64,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'di',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 64,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 64,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 65,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 63,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 62,
          'last-line' => 69,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setModelName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'modelName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 70,
              'char' => 51,
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
                  'property' => 'model',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'modelName',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 72,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 72,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 74,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 74,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a model on which the query will be executed
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 71,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 70,
          'last-line' => 79,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModelName',
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 82,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 82,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 82,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an internal model name on which the criteria will be applied
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 80,
          'last-line' => 88,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bind',
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 89,
              'char' => 43,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 89,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 89,
              'char' => 63,
            ),
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 91,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 91,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 91,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bind',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 91,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 91,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 91,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 91,
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'bind',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 92,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 92,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 92,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 95,
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
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 95,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 95,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 95,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'bind',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 95,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 95,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 95,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 95,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 95,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'merge',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 95,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 95,
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'bind',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 96,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 96,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 96,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 96,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'bind',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 96,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 96,
                          'char' => 57,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bindParams',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 96,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 96,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 96,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 97,
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'bind',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 98,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'bindParams',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 98,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 98,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 101,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 101,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the bound parameters in the criteria
     * This method replaces all previously set bound parameters
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 90,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 89,
          'last-line' => 107,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bindTypes',
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 108,
              'char' => 47,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 110,
                      'char' => 35,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'bindTypes',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 110,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 110,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 112,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 112,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 113,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the bind types in the criteria
     * This method replaces all previously set bound parameters
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 109,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 108,
          'last-line' => 117,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 118,
              'char' => 43,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'distinct',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 120,
                      'char' => 35,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'distinct',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 120,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 120,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 122,
              'char' => 15,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 122,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 123,
              'char' => 6,
            ),
          ),
          'docblock' => '**
     * Sets SELECT DISTINCT / SELECT ALL flag
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 119,
                  'char' => 6,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 119,
                'char' => 6,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 119,
            'char' => 6,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 118,
          'last-line' => 138,
          'char' => 20,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 139,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 141,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 141,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 141,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 143,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 143,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the columns to be queried
     *
     *```php
     * $criteria->columns(
     *     [
     *         "id",
     *         "name",
     *     ]
     * );
     *```
     *
     * @param string|array columns
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 140,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 140,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 139,
          'last-line' => 172,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 173,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 173,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 173,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 173,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 173,
              'char' => 80,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 173,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 173,
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
                  'variable' => 'mergedJoins',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 175,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'currentJoins',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 175,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 176,
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
                  'variable' => 'join',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 176,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 178,
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
                  'variable' => 'join',
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
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 178,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 178,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 178,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 178,
                        'char' => 38,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alias',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 178,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 178,
                        'char' => 45,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 178,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 178,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 178,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 178,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 180,
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
                  'value' => 'currentJoins',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 180,
                  'char' => 52,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 180,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 180,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 180,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'joins',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 180,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 180,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 180,
                'char' => 52,
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
                        'value' => 'currentJoins',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 181,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 181,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 181,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 181,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'mergedJoins',
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
                                  'type' => 'variable',
                                  'value' => 'currentJoins',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 182,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 182,
                                'char' => 59,
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
                                        'value' => 'join',
                                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                        'line' => 182,
                                        'char' => 66,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 182,
                                      'char' => 66,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 182,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 182,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 182,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 182,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 183,
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
                          'variable' => 'mergedJoins',
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
                                  'value' => 'join',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 184,
                                  'char' => 40,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 184,
                                'char' => 40,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 184,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 184,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 185,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 186,
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
                      'variable' => 'mergedJoins',
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
                              'value' => 'join',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 187,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 187,
                            'char' => 36,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 187,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 187,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 190,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'joins',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 190,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mergedJoins',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 190,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 190,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 192,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 192,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 193,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->join(
     *     Robots::class
     * );
     *
     * $criteria->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id"
     * );
     *
     * $criteria->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *
     * $criteria->join(
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 174,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 174,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 174,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 173,
          'last-line' => 214,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 215,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 215,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 215,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 215,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 215,
              'char' => 85,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 217,
                  'char' => 21,
                ),
                'name' => 'join',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 217,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 217,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 217,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 217,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'alias',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 217,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 217,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'INNER',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 217,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 217,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 217,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 218,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->innerJoin(
     *     Robots::class
     * );
     *
     * $criteria->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id"
     * );
     *
     * $criteria->innerJoin(
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 216,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 216,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 216,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 215,
          'last-line' => 230,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 231,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 231,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 231,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 231,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 231,
              'char' => 84,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 233,
                  'char' => 21,
                ),
                'name' => 'join',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 233,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 233,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 233,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 233,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'alias',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 233,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 233,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'LEFT',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 233,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 233,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 233,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 234,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a LEFT join to the query
     *
     *```php
     * $criteria->leftJoin(
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 232,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 232,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 232,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 231,
          'last-line' => 246,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 247,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 247,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 247,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 247,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 247,
              'char' => 77,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 249,
                  'char' => 21,
                ),
                'name' => 'join',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 249,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 249,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 249,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 249,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'alias',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 249,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 249,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'RIGHT',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 249,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 249,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 249,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 250,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a RIGHT join to the query
     *
     *```php
     * $criteria->rightJoin(
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 248,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 248,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 248,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 247,
          'last-line' => 254,
          'char' => 19,
        ),
        12 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 255,
              'char' => 45,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 255,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 255,
              'char' => 68,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 255,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 255,
              'char' => 90,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 257,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'currentBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 257,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 259,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 259,
                      'char' => 36,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 259,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 259,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 264,
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
                    'value' => 'bindParams',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 264,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 264,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 264,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 264,
                'char' => 39,
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
                      'value' => 'currentBindParams',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 265,
                      'char' => 60,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 265,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 265,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 265,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'bind',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 265,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 265,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 265,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bind',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 266,
                              'char' => 38,
                            ),
                          ),
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
                                  'type' => 'variable',
                                  'value' => 'currentBindParams',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 267,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 267,
                                'char' => 38,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'bindParams',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 269,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 269,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 269,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 269,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 270,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bind',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 271,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindParams',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 271,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 271,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 272,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 273,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 278,
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
                    'value' => 'bindTypes',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 278,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 278,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 278,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 278,
                'char' => 38,
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
                      'value' => 'currentBindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 279,
                      'char' => 64,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 279,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 279,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 279,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'bindTypes',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 279,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 279,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 279,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 280,
                              'char' => 43,
                            ),
                          ),
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
                                  'type' => 'variable',
                                  'value' => 'currentBindTypes',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 281,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 281,
                                'char' => 37,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'bindTypes',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 283,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 283,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 283,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 283,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 284,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bindTypes',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 285,
                              'char' => 43,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bindTypes',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 285,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 285,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 286,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 287,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 289,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 289,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 290,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the conditions parameter in the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 256,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 256,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 256,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 255,
          'last-line' => 294,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 295,
              'char' => 48,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 295,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 295,
              'char' => 71,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 295,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 295,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 297,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 299,
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
                  'value' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 299,
                  'char' => 62,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 299,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 299,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 299,
                    'char' => 49,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 299,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 299,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 299,
                'char' => 62,
              ),
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 300,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 300,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 300,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') AND (',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 300,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 300,
                            'char' => 62,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 300,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 300,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 300,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 300,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 300,
                      'char' => 78,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 301,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 303,
              'char' => 14,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 303,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 303,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 303,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 303,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 303,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 303,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 303,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 303,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 304,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an AND operator
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 296,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 296,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 296,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 295,
          'last-line' => 308,
          'char' => 19,
        ),
        14 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 309,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 309,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 309,
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 309,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 309,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 311,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 313,
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
                  'value' => 'currentConditions',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 313,
                  'char' => 62,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 313,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 313,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 313,
                    'char' => 49,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 313,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 313,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 313,
                'char' => 62,
              ),
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 314,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentConditions',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 314,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 314,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ') OR (',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 314,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 314,
                            'char' => 61,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 314,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 314,
                          'char' => 74,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 314,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 314,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 314,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 315,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 317,
              'char' => 14,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 317,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 317,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 317,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 317,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 317,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindTypes',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 317,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 317,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 317,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 318,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an OR operator
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 310,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 310,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 310,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 309,
          'last-line' => 326,
          'char' => 19,
        ),
        15 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 327,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 327,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 327,
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
                  'variable' => 'hiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 329,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'minimumKey',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 329,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 329,
                  'char' => 53,
                ),
                3 => 
                array (
                  'variable' => 'maximumKey',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 329,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
                  'variable' => 'hiddenParam',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 331,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 331,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 331,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 331,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 332,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 332,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 332,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 332,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 337,
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
                  'variable' => 'minimumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'ACP',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 337,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 337,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 337,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 337,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 342,
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
                  'variable' => 'maximumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'ACP',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 342,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nextHiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 342,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 342,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 342,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 348,
              'char' => 12,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 348,
                  'char' => 14,
                ),
                'name' => 'andWhere',
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 349,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' BETWEEN :',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 349,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 349,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'minimumKey',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 349,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 349,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ': AND :',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 349,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 349,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximumKey',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 349,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 349,
                        'char' => 67,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 349,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 349,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 349,
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
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 351,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minimum',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 351,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 351,
                          'char' => 36,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximumKey',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 352,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximum',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 353,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 353,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 354,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 354,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 354,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 356,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'incr',
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 356,
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 357,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 357,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 359,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 359,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 360,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->betweenWhere("price", 100.25, 200.50);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 328,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 328,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 328,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 327,
          'last-line' => 368,
          'char' => 19,
        ),
        16 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 369,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 369,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 369,
              'char' => 75,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 371,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 371,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 372,
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
                  'variable' => 'minimumKey',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 372,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'maximumKey',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 372,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 374,
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
                  'variable' => 'hiddenParam',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 374,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 374,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 374,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 374,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 376,
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
                  'variable' => 'nextHiddenParam',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 376,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 376,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 376,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 376,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 381,
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
                      'value' => 'ACP',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 381,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 381,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 381,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 381,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 386,
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
                  'variable' => 'maximumKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'ACP',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 386,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nextHiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 386,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 386,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 386,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 392,
              'char' => 12,
            ),
            6 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 392,
                  'char' => 14,
                ),
                'name' => 'andWhere',
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 393,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' NOT BETWEEN :',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 393,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 393,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'minimumKey',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 393,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 393,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ': AND :',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 393,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 393,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximumKey',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 393,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 393,
                        'char' => 72,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 393,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 393,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 393,
                    'char' => 75,
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
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 395,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minimum',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 395,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 395,
                          'char' => 36,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximumKey',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 396,
                            'char' => 27,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'maximum',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 397,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 397,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 398,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 398,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 398,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 400,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'incr',
                  'variable' => 'nextHiddenParam',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 400,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 402,
              'char' => 11,
            ),
            8 => 
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
                    'value' => 'nextHiddenParam',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 402,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 402,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 404,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 404,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 405,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->notBetweenWhere("price", 100.25, 200.50);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 370,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 369,
          'last-line' => 413,
          'char' => 19,
        ),
        17 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 414,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 414,
              'char' => 56,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 416,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 416,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 417,
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
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 417,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'bindKeys',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 417,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 418,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 418,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'queryKey',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 418,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 420,
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
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 420,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 420,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 420,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 420,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 421,
                      'char' => 18,
                    ),
                    'name' => 'andWhere',
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
                              'type' => 'variable',
                              'value' => 'expr',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 421,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' != ',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 421,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 421,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 421,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 421,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 421,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 421,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 423,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 423,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 424,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 426,
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
                  'variable' => 'hiddenParam',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 426,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 426,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 426,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 426,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 428,
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
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 428,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 428,
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 429,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 429,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 431,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 431,
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
                          'value' => 'ACP',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 435,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hiddenParam',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 435,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 435,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 435,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 437,
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
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 437,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 437,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 437,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 437,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 437,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 437,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 439,
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
                      'variable' => 'bindKeys',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'queryKey',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 439,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 439,
                      'char' => 38,
                    ),
                    1 => 
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
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 440,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 440,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 440,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 442,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 442,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 443,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 449,
              'char' => 12,
            ),
            7 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 449,
                  'char' => 14,
                ),
                'name' => 'andWhere',
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 450,
                            'char' => 18,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' IN (',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 450,
                            'char' => 26,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 450,
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 450,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 450,
                              'char' => 35,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'bindKeys',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 450,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 450,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 450,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 450,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ')',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 450,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 450,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 450,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 452,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 452,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 452,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 454,
              'char' => 11,
            ),
            8 => 
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 454,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 454,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 456,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 456,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 457,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition to the current conditions
     *
     * ```php
     * $criteria->inWhere("id", [1, 2, 3]);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 415,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 415,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 415,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 414,
          'last-line' => 465,
          'char' => 19,
        ),
        18 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 466,
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 466,
              'char' => 59,
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 468,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 468,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 469,
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
                  'variable' => 'bindParams',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 469,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'bindKeys',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 469,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 470,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 470,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 472,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 472,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hiddenParamNumber',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 472,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 472,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 472,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 474,
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
                  'variable' => 'bindParams',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 474,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 474,
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 475,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 475,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 477,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 477,
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
                          'value' => 'ACP',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 481,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hiddenParam',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 481,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 481,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 481,
                      'char' => 40,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'bindKeys',
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
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 482,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 482,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 482,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 482,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 482,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 482,
                      'char' => 41,
                    ),
                    2 => 
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
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 483,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 483,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 483,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 485,
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
                      'variable' => 'hiddenParam',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 485,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 486,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 492,
              'char' => 12,
            ),
            6 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 492,
                  'char' => 14,
                ),
                'name' => 'andWhere',
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'expr',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 493,
                            'char' => 18,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' NOT IN (',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 493,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 493,
                          'char' => 30,
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
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 493,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 493,
                              'char' => 39,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'bindKeys',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 493,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 493,
                              'char' => 49,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 493,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 493,
                        'char' => 51,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ')',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 493,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 493,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 493,
                    'char' => 54,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bindParams',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 495,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 495,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 495,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 497,
              'char' => 11,
            ),
            7 => 
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 497,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 497,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 499,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 499,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 500,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition to the current conditions
     *
     *```php
     * $criteria->notInWhere("id", [1, 2, 3]);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 467,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 467,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 467,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 466,
          'last-line' => 504,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'conditions',
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 505,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 507,
                      'char' => 36,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 507,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 507,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 509,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 509,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 510,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the conditions parameter to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 506,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 506,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 506,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 505,
          'last-line' => 514,
          'char' => 19,
        ),
        20 => 
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
              'name' => 'orderColumns',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 515,
              'char' => 49,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'order',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 517,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'orderColumns',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 517,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 517,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 519,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 519,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 520,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the order-by clause to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 516,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 516,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 516,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 515,
          'last-line' => 524,
          'char' => 19,
        ),
        21 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 525,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 527,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 527,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 527,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 529,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 529,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 530,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the group-by clause to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 526,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 526,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 526,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 525,
          'last-line' => 534,
          'char' => 19,
        ),
        22 => 
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
              'name' => 'having',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 535,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'having',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 537,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'having',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 537,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 537,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 539,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 539,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 540,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the having clause to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 536,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 536,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 536,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 535,
          'last-line' => 550,
          'char' => 19,
        ),
        23 => 
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
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 551,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 551,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 551,
              'char' => 52,
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
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 553,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 553,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 553,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 553,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 554,
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
                  'variable' => 'offset',
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
                          'value' => 'offset',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 554,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 554,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 554,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 554,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 556,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'limit',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 556,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 556,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 556,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 556,
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
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 557,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 558,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 560,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'limit',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 560,
                      'char' => 31,
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
                          'value' => 'number',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 561,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'limit',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 561,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 561,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'offset',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 562,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'offset',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 563,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 563,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 563,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 563,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 565,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 565,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 566,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the limit parameter to the criteria.
     *
     * ```php
     * $criteria->limit(100);
     * $criteria->limit(100, 200);
     * $criteria->limit("100", "200");
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 552,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 552,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 552,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 551,
          'last-line' => 570,
          'char' => 19,
        ),
        24 => 
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
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 571,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 571,
              'char' => 52,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'for_update',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 573,
                      'char' => 36,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'forUpdate',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 573,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 573,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 575,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 575,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 576,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the "for_update" parameter to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 572,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 572,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 572,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 571,
          'last-line' => 580,
          'char' => 19,
        ),
        25 => 
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
              'name' => 'sharedLock',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 581,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 581,
              'char' => 54,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'shared_lock',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 583,
                      'char' => 37,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sharedLock',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 583,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 583,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 585,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 585,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 586,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the "shared_lock" parameter to the criteria
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 582,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 582,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 582,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 581,
          'last-line' => 591,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'cache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 592,
              'char' => 39,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 594,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cache',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 594,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 594,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 596,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 596,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 597,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cache options in the criteria
     * This method replaces all previously set cache options
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 593,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 593,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 593,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 592,
          'last-line' => 601,
          'char' => 19,
        ),
        27 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'conditions',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 604,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 606,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 606,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 606,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 606,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 606,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 606,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 606,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 606,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 606,
                'char' => 56,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 607,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 608,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 610,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'conditions',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 610,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 611,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the conditions parameter in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 602,
                'char' => 42,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 603,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 603,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 602,
          'last-line' => 617,
          'char' => 19,
        ),
        28 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 620,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 622,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'columns',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 622,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 622,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 622,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 622,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 622,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 622,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 622,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 622,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 623,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 624,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 626,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'columns',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 626,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 627,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the columns to be queried
     *
     * @return string|array|null
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 618,
                'char' => 44,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 619,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 619,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 618,
          'last-line' => 631,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConditions',
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 634,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 636,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'conditions',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 636,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 636,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 636,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 636,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 636,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 636,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 636,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 636,
                'char' => 56,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 637,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 638,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 640,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'conditions',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 640,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 641,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the conditions parameter in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 632,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 633,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 633,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 632,
          'last-line' => 649,
          'char' => 19,
        ),
        30 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'limit',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 652,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 654,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'limit',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 654,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 654,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 654,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 654,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'limit',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 654,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 654,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 654,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 654,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 655,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 656,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 658,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'limit',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 658,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 659,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the limit parameter in the criteria, which will be an integer if
     * limit was set without an offset, an array with \'number\' and \'offset\' keys
     * if an offset was set with the limit, or null if limit has not been set.
     *
     * @return int|array|null
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 650,
                'char' => 42,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 651,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 651,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 650,
          'last-line' => 663,
          'char' => 19,
        ),
        31 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'order',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 666,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 668,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'order',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 668,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 668,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 668,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 668,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'order',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 668,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 668,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 668,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 668,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 669,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 670,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 672,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'order',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 672,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 673,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the order clause in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 664,
                'char' => 44,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 665,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 665,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 664,
          'last-line' => 677,
          'char' => 19,
        ),
        32 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'group',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 680,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 682,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 682,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 682,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 682,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 682,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 682,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 682,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 682,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 682,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 683,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 684,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 686,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'group',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 686,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 687,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the group clause in the criteria
     *',
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 678,
          'last-line' => 691,
          'char' => 19,
        ),
        33 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'having',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 694,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 696,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'having',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 696,
                    'char' => 48,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 696,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 696,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 696,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'having',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 696,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 696,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 696,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 696,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 697,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 698,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 700,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'having',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 700,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 701,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the having clause in the criteria
     *',
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 692,
          'last-line' => 705,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 708,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 708,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 708,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 709,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the parameters defined in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 707,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 707,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 706,
          'last-line' => 713,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'fromInput',
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
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 714,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 714,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 714,
              'char' => 80,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 714,
              'char' => 93,
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
                'type' => 'string',
                'value' => 'AND',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 714,
                'char' => 117,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 714,
              'char' => 117,
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
                  'variable' => 'attribute',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'metaData',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 52,
                ),
                5 => 
                array (
                  'variable' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 59,
                ),
                6 => 
                array (
                  'variable' => 'dataTypes',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 716,
                  'char' => 70,
                ),
                7 => 
                array (
                  'variable' => 'criteria',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 717,
                  'char' => 21,
                ),
                8 => 
                array (
                  'variable' => 'columnMap',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 717,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 718,
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
                  'variable' => 'conditions',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 718,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'bind',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 718,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 720,
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
                  'variable' => 'conditions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 720,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 720,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 722,
              'char' => 10,
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
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 722,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 722,
                    'char' => 22,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 722,
                'char' => 24,
              ),
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
                      'variable' => 'metaData',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 723,
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
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 723,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 723,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 723,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 723,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 725,
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
                      'variable' => 'model',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'modelName',
                        'dynamic' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 725,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 725,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 725,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 725,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 725,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 725,
                      'char' => 57,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'dataTypes',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 726,
                          'char' => 38,
                        ),
                        'name' => 'getDataTypes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'model',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 726,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 726,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 726,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 726,
                      'char' => 58,
                    ),
                    2 => 
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
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 727,
                          'char' => 38,
                        ),
                        'name' => 'getReverseColumnMap',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'model',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 727,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 727,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 727,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 727,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 732,
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
                      'variable' => 'bind',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 732,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 732,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 734,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 734,
                    'char' => 38,
                  ),
                  'key' => 'field',
                  'value' => 'value',
                  'reverse' => 0,
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
                              'type' => 'variable',
                              'value' => 'columnMap',
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 735,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 735,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 735,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 735,
                          'char' => 47,
                        ),
                        'right' => 
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
                                'value' => 'columnMap',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 735,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 735,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 735,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 735,
                        'char' => 66,
                      ),
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
                              'variable' => 'attribute',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnMap',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 736,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 736,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 736,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 736,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 737,
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
                              'variable' => 'attribute',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 738,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 738,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 739,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 741,
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
                          'value' => 'type',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 741,
                          'char' => 53,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dataTypes',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 741,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attribute',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 741,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 741,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 741,
                        'char' => 53,
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
                              'type' => 'not-identical',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 742,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'null',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 742,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 742,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'not-identical',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 742,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 742,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 742,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 742,
                            'char' => 53,
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
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 743,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'Column',
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 743,
                                    'char' => 57,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'TYPE_VARCHAR',
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 743,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 743,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 743,
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
                                      'assign-type' => 'variable-append',
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
                                                'value' => '[',
                                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                                'line' => 747,
                                                'char' => 50,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'field',
                                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                                'line' => 747,
                                                'char' => 58,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                              'line' => 747,
                                              'char' => 58,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '] LIKE :',
                                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                              'line' => 747,
                                              'char' => 69,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 747,
                                            'char' => 69,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'field',
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 747,
                                            'char' => 77,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 747,
                                          'char' => 77,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ':',
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 747,
                                          'char' => 80,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                        'line' => 747,
                                        'char' => 80,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 747,
                                      'char' => 80,
                                    ),
                                    1 => 
                                    array (
                                      'assign-type' => 'array-index',
                                      'operator' => 'assign',
                                      'variable' => 'bind',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'field',
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 748,
                                          'char' => 43,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '%',
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 748,
                                            'char' => 49,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'value',
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 748,
                                            'char' => 57,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 748,
                                          'char' => 57,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '%',
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 748,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                        'line' => 748,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 748,
                                      'char' => 60,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 750,
                                  'char' => 36,
                                ),
                                1 => 
                                array (
                                  'type' => 'continue',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 751,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 756,
                              'char' => 27,
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
                                            'value' => '[',
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 756,
                                            'char' => 46,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'field',
                                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                            'line' => 756,
                                            'char' => 54,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 756,
                                          'char' => 54,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '] = :',
                                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                          'line' => 756,
                                          'char' => 62,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                        'line' => 756,
                                        'char' => 62,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'field',
                                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                        'line' => 756,
                                        'char' => 70,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 756,
                                      'char' => 70,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':',
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 756,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 756,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 756,
                                  'char' => 73,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'bind',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                      'line' => 757,
                                      'char' => 39,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 757,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 757,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 758,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 759,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 760,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 761,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 766,
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
                  'variable' => 'criteria',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'self',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 766,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 766,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 768,
              'char' => 10,
            ),
            5 => 
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
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 768,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 768,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 768,
                'char' => 30,
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
                      'value' => 'criteria',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 769,
                      'char' => 22,
                    ),
                    'name' => 'where',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
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
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' ',
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 771,
                                    'char' => 23,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'operator',
                                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                    'line' => 771,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 771,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ',
                                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                  'line' => 771,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 771,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 771,
                              'char' => 37,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'conditions',
                                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                                'line' => 773,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                              'line' => 773,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 774,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 774,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 774,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 776,
                  'char' => 20,
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
                      'value' => 'criteria',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 776,
                      'char' => 22,
                    ),
                    'name' => 'bind',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'bind',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 776,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 776,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 776,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 777,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 779,
              'char' => 16,
            ),
            6 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'criteria',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 779,
                  'char' => 18,
                ),
                'name' => 'setModelName',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'modelName',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 779,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 779,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 779,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 781,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'criteria',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 781,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 782,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a Phalcon\\Mvc\\Model\\Criteria based on an input array like $_POST
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 715,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 715,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 715,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 714,
          'last-line' => 793,
          'char' => 26,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createBuilder',
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 796,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'manager',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 796,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'builder',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 796,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 798,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 798,
                      'char' => 30,
                    ),
                    'name' => 'getDI',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 798,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 798,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 800,
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
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 800,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 800,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 800,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 800,
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
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 801,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 801,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 803,
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
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 803,
                      'char' => 18,
                    ),
                    'name' => 'setDI',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 803,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 803,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 803,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 804,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
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
                  'variable' => 'manager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 806,
                      'char' => 77,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 806,
                        'char' => 52,
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
                            'value' => 'modelsManager',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 806,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 806,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 806,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 806,
                    'char' => 77,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 806,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 811,
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
                  'variable' => 'builder',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 811,
                      'char' => 31,
                    ),
                    'name' => 'createBuilder',
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
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 811,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                            'line' => 811,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 811,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 811,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 811,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 811,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 813,
              'char' => 15,
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
                  'value' => 'builder',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 813,
                  'char' => 17,
                ),
                'name' => 'from',
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
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 813,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'model',
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 813,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 813,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 813,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 813,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 815,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'builder',
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 815,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 816,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates a query builder from criteria.
     *
     * ```php
     * $builder = Robots::query()
     *     ->where("type = :type:")
     *     ->bind(["type" => "mechanical"])
     *     ->createBuilder();
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
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 795,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 795,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 795,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 794,
          'last-line' => 820,
          'char' => 19,
        ),
        37 => 
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 823,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 825,
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
                  'variable' => 'model',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 825,
                      'char' => 26,
                    ),
                    'name' => 'getModelName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 825,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 825,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 827,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 827,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 827,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 827,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 827,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 827,
                'char' => 44,
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
                          'value' => 'Model name must be string',
                          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                          'line' => 828,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 828,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 828,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 829,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 831,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 1,
                'class' => 'model',
                'dynamic' => 0,
                'name' => 'find',
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
                        'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                        'line' => 832,
                        'char' => 18,
                      ),
                      'name' => 'getParams',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                      'line' => 833,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                    'line' => 833,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 833,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
              'line' => 834,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Executes a find using the parameters built with the criteria
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
                  'value' => 'ResultsetInterface',
                  'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                  'line' => 822,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
                'line' => 822,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
            'line' => 822,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
          'line' => 821,
          'last-line' => 835,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
      'line' => 39,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Criteria.zep',
    'line' => 39,
    'char' => 5,
  ),
);