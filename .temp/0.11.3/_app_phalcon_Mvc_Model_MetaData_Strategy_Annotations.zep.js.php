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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData\\Strategy',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 14,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 17,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 18,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
    'line' => 20,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Annotations',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
        'line' => 21,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 25,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 25,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 25,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 25,
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
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 27,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 27,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'reflection',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 27,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'propertiesAnnotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 27,
                  'char' => 70,
                ),
                4 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 27,
                  'char' => 80,
                ),
                5 => 
                array (
                  'variable' => 'propAnnotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 28,
                  'char' => 28,
                ),
                6 => 
                array (
                  'variable' => 'columnAnnotation',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 28,
                  'char' => 46,
                ),
                7 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 28,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 29,
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
                  'variable' => 'orderedColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 29,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'reversedColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 29,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 30,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hasReversedColumn',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 30,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 32,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 32,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 32,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 32,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 32,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 32,
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
                          'value' => 'The dependency injector is invalid',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 33,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 33,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 33,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 34,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 36,
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
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 36,
                      'char' => 37,
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
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 36,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 36,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 36,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 36,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 38,
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
                  'variable' => 'className',
                  'expr' => 
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 38,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 38,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 38,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 38,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'reflection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 39,
                      'char' => 38,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 39,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 39,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 39,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 39,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 41,
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
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 41,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 41,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 41,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 41,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 41,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'No annotations were found in class ',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 43,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 44,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 44,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 44,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 44,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 50,
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
                  'variable' => 'propertiesAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 50,
                      'char' => 48,
                    ),
                    'name' => 'getPropertiesAnnotations',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 50,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 50,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 52,
              'char' => 10,
            ),
            8 => 
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
                          'value' => 'propertiesAnnotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 52,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 52,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 52,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 52,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 52,
                'char' => 51,
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
                            'value' => 'No properties with annotations were found in class ',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 54,
                            'char' => 69,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 55,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 55,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 55,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 55,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 56,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 58,
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
                  'variable' => 'orderedColumnMap',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 58,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 58,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'reversedColumnMap',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 59,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 59,
                  'char' => 35,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'hasReversedColumn',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 60,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 60,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 62,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'propertiesAnnotations',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 62,
                'char' => 64,
              ),
              'key' => 'property',
              'value' => 'propAnnotations',
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'propAnnotations',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 66,
                        'char' => 33,
                      ),
                      'name' => 'has',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 66,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 66,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 66,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 66,
                    'char' => 46,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 68,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 73,
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
                      'variable' => 'columnAnnotation',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'propAnnotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 73,
                          'char' => 52,
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
                              'value' => 'Column',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 73,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 73,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 73,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 73,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 78,
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
                      'variable' => 'columnName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnAnnotation',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 78,
                          'char' => 47,
                        ),
                        'name' => 'getNamedParameter',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'column',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 78,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 78,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 78,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 78,
                      'char' => 73,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 80,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 80,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 80,
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
                          'variable' => 'columnName',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'property',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 81,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 81,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 84,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'orderedColumnMap',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 84,
                          'char' => 44,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'property',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 84,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 84,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'reversedColumnMap',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'property',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 85,
                          'char' => 43,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnName',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 85,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 85,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 87,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hasReversedColumn',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 87,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 87,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnName',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 87,
                        'char' => 50,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'property',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 87,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 87,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 87,
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
                          'variable' => 'hasReversedColumn',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 88,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 88,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 89,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 92,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'hasReversedColumn',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 92,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 92,
                'char' => 31,
              ),
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
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 93,
                          'char' => 25,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 93,
                        'char' => 25,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 93,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 93,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 93,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 99,
              'char' => 14,
            ),
            12 => 
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 99,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 99,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reversedColumnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 99,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 99,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 99,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 100,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
          'line' => 25,
          'last-line' => 104,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 105,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 105,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 105,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 105,
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
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 107,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 107,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'reflection',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 107,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'propertiesAnnotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 107,
                  'char' => 70,
                ),
                4 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 107,
                  'char' => 80,
                ),
                5 => 
                array (
                  'variable' => 'propAnnotations',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 108,
                  'char' => 28,
                ),
                6 => 
                array (
                  'variable' => 'columnAnnotation',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 108,
                  'char' => 46,
                ),
                7 => 
                array (
                  'variable' => 'columnName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 108,
                  'char' => 58,
                ),
                8 => 
                array (
                  'variable' => 'feature',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 108,
                  'char' => 67,
                ),
                9 => 
                array (
                  'variable' => 'fieldTypes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 108,
                  'char' => 79,
                ),
                10 => 
                array (
                  'variable' => 'fieldBindTypes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 109,
                  'char' => 27,
                ),
                11 => 
                array (
                  'variable' => 'numericTyped',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 109,
                  'char' => 41,
                ),
                12 => 
                array (
                  'variable' => 'primaryKeys',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 109,
                  'char' => 54,
                ),
                13 => 
                array (
                  'variable' => 'nonPrimaryKeys',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 109,
                  'char' => 70,
                ),
                14 => 
                array (
                  'variable' => 'identityField',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 110,
                  'char' => 26,
                ),
                15 => 
                array (
                  'variable' => 'notNull',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 110,
                  'char' => 35,
                ),
                16 => 
                array (
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 110,
                  'char' => 47,
                ),
                17 => 
                array (
                  'variable' => 'defaultValues',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 110,
                  'char' => 62,
                ),
                18 => 
                array (
                  'variable' => 'defaultValue',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 110,
                  'char' => 76,
                ),
                19 => 
                array (
                  'variable' => 'emptyStringValues',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 111,
                  'char' => 30,
                ),
                20 => 
                array (
                  'variable' => 'skipOnInsert',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 111,
                  'char' => 44,
                ),
                21 => 
                array (
                  'variable' => 'skipOnUpdate',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 111,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 113,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 113,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 113,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 113,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 113,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 113,
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
                          'value' => 'The dependency injector is invalid',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 114,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 114,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 114,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 117,
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
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 117,
                      'char' => 37,
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
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 117,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 117,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 117,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 117,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 119,
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
                  'variable' => 'className',
                  'expr' => 
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 119,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 119,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 119,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 119,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'reflection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 120,
                      'char' => 38,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 120,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 120,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 120,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 120,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 122,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 122,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 122,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 122,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 122,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 122,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'No annotations were found in class ',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 124,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 125,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 125,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 125,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 125,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 126,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 131,
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
                  'variable' => 'propertiesAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 131,
                      'char' => 48,
                    ),
                    'name' => 'getPropertiesAnnotations',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 131,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 131,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 133,
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
                          'value' => 'propertiesAnnotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 133,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 133,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 133,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 133,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 133,
                'char' => 51,
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
                            'value' => 'No properties with annotations were found in class ',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 135,
                            'char' => 69,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 136,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 136,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 136,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 136,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 142,
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
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 142,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 142,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'primaryKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 143,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 143,
                  'char' => 29,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'nonPrimaryKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 144,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 144,
                  'char' => 32,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'numericTyped',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 145,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 145,
                  'char' => 30,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'notNull',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 146,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 146,
                  'char' => 25,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fieldTypes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 147,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 147,
                  'char' => 28,
                ),
                6 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fieldBindTypes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 148,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 148,
                  'char' => 32,
                ),
                7 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'identityField',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 149,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 149,
                  'char' => 34,
                ),
                8 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'skipOnInsert',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 150,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 150,
                  'char' => 30,
                ),
                9 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'skipOnUpdate',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 151,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 151,
                  'char' => 30,
                ),
                10 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'defaultValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 152,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 152,
                  'char' => 31,
                ),
                11 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'emptyStringValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 153,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 153,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 155,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'propertiesAnnotations',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 155,
                'char' => 64,
              ),
              'key' => 'property',
              'value' => 'propAnnotations',
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'propAnnotations',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 160,
                        'char' => 33,
                      ),
                      'name' => 'has',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'Column',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 160,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 160,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 160,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 160,
                    'char' => 46,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 162,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 167,
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
                      'variable' => 'columnAnnotation',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'propAnnotations',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 167,
                          'char' => 52,
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
                              'value' => 'Column',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 167,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 167,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 167,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 167,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 172,
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
                      'variable' => 'columnName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnAnnotation',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 172,
                          'char' => 47,
                        ),
                        'name' => 'getNamedParameter',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'column',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 172,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 172,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 172,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 172,
                      'char' => 73,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 174,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 174,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 174,
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
                          'variable' => 'columnName',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'property',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 175,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 175,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 176,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 181,
                  'char' => 15,
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
                      'variable' => 'feature',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnAnnotation',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 181,
                          'char' => 44,
                        ),
                        'name' => 'getNamedParameter',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 181,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 181,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 181,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 181,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 183,
                  'char' => 18,
                ),
                5 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'feature',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 183,
                    'char' => 28,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'biginteger',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 184,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 185,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 185,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIGINTEGER',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 185,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 185,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 185,
                              'char' => 73,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 186,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 186,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 186,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 186,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 186,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 187,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 187,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 187,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 188,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 190,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 190,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'bit',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 190,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 191,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 191,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BIT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 191,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 191,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 191,
                              'char' => 66,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 192,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 192,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 192,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 192,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 192,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 193,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 193,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 193,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 194,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 196,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 196,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'blob',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 196,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 197,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 197,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 197,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 197,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 197,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 198,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 198,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 198,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 198,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 198,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 199,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 201,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 201,
                      'char' => 20,
                    ),
                    3 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'boolean',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 201,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 202,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 202,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_BOOLEAN',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 202,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 202,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 202,
                              'char' => 70,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 203,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 203,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BOOL',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 203,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 203,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 203,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 204,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 206,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 206,
                      'char' => 20,
                    ),
                    4 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'char',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 206,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 207,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 207,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_CHAR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 207,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 207,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 207,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 208,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 208,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 208,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 208,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 208,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 209,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 211,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 211,
                      'char' => 20,
                    ),
                    5 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'date',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 211,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 212,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 212,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATE',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 212,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 212,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 212,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 213,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 213,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 213,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 213,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 213,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 214,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 216,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 216,
                      'char' => 20,
                    ),
                    6 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'datetime',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 216,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 217,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 217,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DATETIME',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 217,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 217,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 217,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 218,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 218,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 218,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 218,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 218,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 219,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 221,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 221,
                      'char' => 20,
                    ),
                    7 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'decimal',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 221,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 222,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 222,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DECIMAL',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 222,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 222,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 222,
                              'char' => 70,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 223,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 223,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 223,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 223,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 223,
                              'char' => 80,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 224,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 224,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 224,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 225,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 227,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 227,
                      'char' => 20,
                    ),
                    8 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'double',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 227,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 228,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 228,
                                  'char' => 69,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_DOUBLE',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 228,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 228,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 228,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 229,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 229,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 229,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 229,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 229,
                              'char' => 80,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 230,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 230,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 230,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 231,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 233,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 233,
                      'char' => 20,
                    ),
                    9 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'enum',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 233,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 234,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 234,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_ENUM',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 234,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 234,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 234,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 235,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 235,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 235,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 235,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 235,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 236,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 236,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 236,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 237,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 239,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 239,
                      'char' => 20,
                    ),
                    10 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'float',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 239,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 240,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 240,
                                  'char' => 68,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_FLOAT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 240,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 240,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 240,
                              'char' => 68,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 241,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 241,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_DECIMAL',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 241,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 241,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 241,
                              'char' => 80,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 242,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 242,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 242,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 243,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 245,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 245,
                      'char' => 20,
                    ),
                    11 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'integer',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 245,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 246,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 246,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_INTEGER',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 246,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 246,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 246,
                              'char' => 70,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 247,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 247,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 247,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 247,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 247,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 248,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 248,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 248,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 249,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 251,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 251,
                      'char' => 20,
                    ),
                    12 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'json',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 251,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 252,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 252,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_JSON',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 252,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 252,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 252,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 253,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 253,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 253,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 253,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 253,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 254,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 256,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 256,
                      'char' => 20,
                    ),
                    13 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'jsonb',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 256,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 257,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 257,
                                  'char' => 68,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_JSONB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 257,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 257,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 257,
                              'char' => 68,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 258,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 258,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 258,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 258,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 258,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 259,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 261,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 261,
                      'char' => 20,
                    ),
                    14 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'longblob',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 261,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 262,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 262,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGBLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 262,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 262,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 262,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 263,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 263,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 263,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 263,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 263,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 264,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 266,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 266,
                      'char' => 20,
                    ),
                    15 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'longtext',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 266,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 267,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 267,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_LONGTEXT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 267,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 267,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 267,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 268,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 268,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 268,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 268,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 268,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 269,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 271,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 271,
                      'char' => 20,
                    ),
                    16 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'mediumblob',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 271,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 272,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 272,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMBLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 272,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 272,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 272,
                              'char' => 73,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 273,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 273,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 273,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 273,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 273,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 274,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 276,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 276,
                      'char' => 20,
                    ),
                    17 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'mediumint',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 276,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 277,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 277,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMINTEGER',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 277,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 277,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 277,
                              'char' => 76,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 278,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 278,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 278,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 278,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 278,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 279,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 279,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 279,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 280,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 282,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 282,
                      'char' => 20,
                    ),
                    18 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'mediumtext',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 282,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 283,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 283,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_MEDIUMTEXT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 283,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 283,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 283,
                              'char' => 73,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 284,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 284,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 284,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 284,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 284,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 285,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 287,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 287,
                      'char' => 20,
                    ),
                    19 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'smallint',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 287,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 288,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 288,
                                  'char' => 75,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_SMALLINTEGER',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 288,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 288,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 288,
                              'char' => 75,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 289,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 289,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 289,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 289,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 289,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 290,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 290,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 290,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 291,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 293,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 293,
                      'char' => 20,
                    ),
                    20 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'text',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 293,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 294,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 294,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TEXT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 294,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 294,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 294,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 295,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 295,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 295,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 295,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 295,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 296,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 298,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 298,
                      'char' => 20,
                    ),
                    21 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'time',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 298,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 299,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 299,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIME',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 299,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 299,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 299,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 300,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 300,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 300,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 300,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 300,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 301,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 303,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 303,
                      'char' => 20,
                    ),
                    22 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'timestamp',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 303,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 304,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 304,
                                  'char' => 72,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TIMESTAMP',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 304,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 304,
                                'char' => 72,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 304,
                              'char' => 72,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 305,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 305,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 305,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 305,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 305,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 306,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 308,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 308,
                      'char' => 20,
                    ),
                    23 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'tinyblob',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 308,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 309,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 309,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYBLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 309,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 309,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 309,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 310,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 310,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_BLOB',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 310,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 310,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 310,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 311,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 313,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 313,
                      'char' => 20,
                    ),
                    24 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'tinyint',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 313,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 314,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 314,
                                  'char' => 74,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYINTEGER',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 314,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 314,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 314,
                              'char' => 74,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 315,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 315,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_INT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 315,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 315,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 315,
                              'char' => 76,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'numericTyped',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 316,
                                  'char' => 48,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 316,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 316,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 317,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 319,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 319,
                      'char' => 20,
                    ),
                    25 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'tinytext',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 319,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 320,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 320,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_TINYTEXT',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 320,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 320,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 320,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 321,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 321,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 321,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 321,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 321,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 322,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 324,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 324,
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
                              'variable' => 'fieldTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 328,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 328,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'TYPE_VARCHAR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 328,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 328,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 328,
                              'char' => 70,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'fieldBindTypes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnName',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 329,
                                  'char' => 50,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Column',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 329,
                                  'char' => 76,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BIND_PARAM_STR',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                  'line' => 329,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                                'line' => 329,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 329,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 330,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 330,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 336,
                  'char' => 14,
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
                      'value' => 'propAnnotations',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 336,
                      'char' => 32,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Primary',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 336,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 336,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 336,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'primaryKeys',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 337,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 337,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 338,
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
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 339,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 339,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 340,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 346,
                  'char' => 14,
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
                      'value' => 'propAnnotations',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 346,
                      'char' => 32,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Identity',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 346,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 346,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 346,
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
                          'variable' => 'identityField',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 347,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 347,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 348,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 353,
                  'char' => 14,
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
                      'value' => 'columnAnnotation',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 353,
                      'char' => 33,
                    ),
                    'name' => 'getNamedParameter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'skip_on_insert',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 353,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 353,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 353,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'skipOnInsert',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 354,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 354,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 355,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 360,
                  'char' => 14,
                ),
                9 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnAnnotation',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 360,
                      'char' => 33,
                    ),
                    'name' => 'getNamedParameter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'skip_on_update',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 360,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 360,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 360,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'skipOnUpdate',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 361,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 361,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 362,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 367,
                  'char' => 14,
                ),
                10 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnAnnotation',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 367,
                      'char' => 33,
                    ),
                    'name' => 'getNamedParameter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'allow_empty_string',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 367,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 367,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 367,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'emptyStringValues',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 368,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 368,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 369,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 374,
                  'char' => 14,
                ),
                11 => 
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
                        'value' => 'columnAnnotation',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 374,
                        'char' => 34,
                      ),
                      'name' => 'getNamedParameter',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'nullable',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 374,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 374,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 374,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 374,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'notNull',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnName',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 375,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 375,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 376,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 382,
                  'char' => 15,
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
                      'variable' => 'defaultValue',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnAnnotation',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 382,
                          'char' => 49,
                        ),
                        'name' => 'getNamedParameter',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'default',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 382,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 382,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 382,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 382,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 383,
                  'char' => 14,
                ),
                13 => 
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 383,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 383,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 383,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnAnnotation',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 383,
                        'char' => 58,
                      ),
                      'name' => 'getNamedParameter',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'nullable',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 383,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 383,
                          'char' => 85,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 383,
                      'char' => 87,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 383,
                    'char' => 87,
                  ),
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
                              'value' => 'columnName',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                              'line' => 384,
                              'char' => 45,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultValue',
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                            'line' => 384,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                          'line' => 384,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 385,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 387,
                  'char' => 15,
                ),
                14 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'attributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnName',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 387,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 387,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                  'line' => 388,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 393,
              'char' => 14,
            ),
            9 => 
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 394,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_ATTRIBUTES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 394,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 394,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 394,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 394,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 395,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_PRIMARY_KEY',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 395,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 395,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'primaryKeys',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 395,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 395,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 396,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_NON_PRIMARY_KEY',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 396,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 396,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'nonPrimaryKeys',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 396,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 396,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 397,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_NOT_NULL',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 397,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 397,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notNull',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 397,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 397,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 398,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 398,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 398,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fieldTypes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 398,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 398,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 399,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES_NUMERIC',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 399,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 399,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'numericTyped',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 399,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 399,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 400,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_IDENTITY_COLUMN',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 400,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 400,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'identityField',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 400,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 400,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 401,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES_BIND',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 401,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 401,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fieldBindTypes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 401,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 401,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 402,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_INSERT',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 402,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 402,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'skipOnInsert',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 402,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 402,
                    'char' => 69,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 403,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_UPDATE',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 403,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 403,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'skipOnUpdate',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 403,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 403,
                    'char' => 69,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 404,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DEFAULT_VALUES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 404,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 404,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValues',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 404,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 404,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 405,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_EMPTY_STRING_VALUES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                        'line' => 405,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 405,
                      'char' => 55,
                    ),
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'emptyStringValues',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                      'line' => 406,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                    'line' => 406,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 406,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
              'line' => 407,
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
                'line' => 106,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
            'line' => 106,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
          'line' => 105,
          'last-line' => 408,
          'char' => 25,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep',
    'line' => 20,
    'char' => 5,
  ),
);