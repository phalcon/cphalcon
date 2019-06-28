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
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Behavior',
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Behavior',
        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
    'line' => 23,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Behavior\\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the datetime when a
 * record is created or updated
 *',
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 29,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 29,
              'char' => 64,
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
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'timestamp',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 31,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 36,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 36,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 36,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 36,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 37,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 38,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 40,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 40,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 40,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 40,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 42,
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 42,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 42,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 42,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 42,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 44,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 49,
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
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 49,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 49,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'field',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 49,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 49,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 49,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 49,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 49,
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
                          'value' => 'The option \'field\' is required',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 50,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 50,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 50,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 53,
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
                  'variable' => 'timestamp',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 53,
                      'char' => 30,
                    ),
                    'name' => 'getTimestamp',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 53,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 53,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 53,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 53,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 59,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 59,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 59,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 59,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 59,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 59,
                'char' => 43,
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
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 60,
                    'char' => 38,
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 61,
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
                              'value' => 'singleField',
                              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                              'line' => 61,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                            'line' => 61,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                              'line' => 61,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                            'line' => 61,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 61,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 62,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 63,
                  'char' => 9,
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 64,
                      'char' => 19,
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 64,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 64,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'timestamp',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 64,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 64,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 64,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 65,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 66,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listens for notifications from the models manager
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
          'line' => 29,
          'last-line' => 68,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getTimestamp',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 68,
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
                  'variable' => 'format',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 70,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'generator',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 70,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 72,
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
                  'value' => 'format',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 72,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 72,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'format',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 72,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 72,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 72,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 76,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 76,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 76,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 79,
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
                  'value' => 'generator',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 79,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 79,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'generator',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 79,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 79,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 79,
                'char' => 48,
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
                          'type' => 'variable',
                          'value' => 'generator',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                          'line' => 83,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 83,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 83,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 83,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'generator',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 83,
                        'char' => 65,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Closure',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 83,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 83,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                    'line' => 83,
                    'char' => 75,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                              'line' => 84,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                            'line' => 84,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                        'line' => 84,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                      'line' => 85,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                  'line' => 86,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 91,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'time',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
                'line' => 91,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
          'line' => 68,
          'last-line' => 93,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/Timestampable.zep',
    'line' => 24,
    'char' => 5,
  ),
);