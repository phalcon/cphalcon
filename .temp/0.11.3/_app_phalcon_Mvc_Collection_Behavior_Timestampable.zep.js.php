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
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Collection\\Behavior',
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
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
        'name' => 'Closure',
        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
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
        'name' => 'Phalcon\\Mvc\\CollectionInterface',
        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
        'line' => 14,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
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
        'name' => 'Phalcon\\Mvc\\Collection\\Behavior',
        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
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
        'name' => 'Phalcon\\Mvc\\Collection\\Exception',
        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
        'line' => 16,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
    'line' => 23,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Collection\\Behavior\\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 *',
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
    'line' => 24,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Timestampable',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Behavior',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notify',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 29,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                'line' => 29,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 29,
              'char' => 69,
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
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'timestamp',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'generator',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 62,
                ),
                5 => 
                array (
                  'variable' => 'format',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 36,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 36,
                    'char' => 17,
                  ),
                  'name' => 'mustTakeAction',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 36,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 36,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 36,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 36,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                'line' => 36,
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
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 37,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 38,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 40,
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
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 40,
                      'char' => 28,
                    ),
                    'name' => 'getOptions',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 40,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 40,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 40,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 40,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 41,
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 41,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 41,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 41,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                'line' => 41,
                'char' => 36,
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
                          'value' => 'field',
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 46,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 46,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'field',
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 46,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 46,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 46,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 46,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 46,
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
                              'value' => 'The option \'field\' is required',
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 47,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 47,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 47,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 48,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 50,
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
                      'variable' => 'timestamp',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 50,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 50,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 52,
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
                      'value' => 'format',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 52,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 52,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'format',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 52,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 52,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 52,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'timestamp',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'date',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'format',
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 56,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                'line' => 56,
                                'char' => 44,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 56,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 56,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 57,
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
                          'value' => 'generator',
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 58,
                          'char' => 56,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 58,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'generator',
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 58,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 58,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 58,
                        'char' => 56,
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
                                'value' => 'generator',
                                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                'line' => 63,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 63,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 63,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 63,
                            'char' => 51,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'instanceof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'generator',
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 64,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Closure',
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 64,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                'line' => 64,
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
                                      'variable' => 'timestamp',
                                      'expr' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'call_user_func',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'generator',
                                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                              'line' => 65,
                                              'char' => 69,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                            'line' => 65,
                                            'char' => 69,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                        'line' => 65,
                                        'char' => 70,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                      'line' => 65,
                                      'char' => 70,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 66,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 67,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 68,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 69,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 74,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'timestamp',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 74,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 74,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 74,
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
                          'variable' => 'timestamp',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'time',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 75,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 75,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 76,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 81,
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
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 81,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 81,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 81,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                    'line' => 81,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 82,
                        'char' => 42,
                      ),
                      'value' => 'singleField',
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
                              'value' => 'model',
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 83,
                              'char' => 27,
                            ),
                            'name' => 'writeAttribute',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleField',
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 83,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                'line' => 83,
                                'char' => 54,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'timestamp',
                                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                  'line' => 83,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                                'line' => 83,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 83,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 84,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 85,
                      'char' => 13,
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                          'line' => 86,
                          'char' => 23,
                        ),
                        'name' => 'writeAttribute',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 86,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 86,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                              'line' => 86,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                            'line' => 86,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                        'line' => 86,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                      'line' => 87,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listens for notifications from the models manager
     *',
          'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
          'line' => 29,
          'last-line' => 90,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior/Timestampable.zep',
    'line' => 24,
    'char' => 5,
  ),
);