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
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Behavior',
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Behavior',
        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
        'line' => 15,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
    'line' => 22,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Behavior\\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as deleted
 * changing the value of a flag column
 *',
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
    'line' => 23,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'SoftDelete',
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
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 28,
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
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 28,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 28,
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
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'updateModel',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'modelsManager',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 71,
                ),
                6 => 
                array (
                  'variable' => 'metaData',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 30,
                  'char' => 81,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 32,
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
                  'type' => 'variable',
                  'value' => 'type',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 32,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'beforeDelete',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 32,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 32,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 34,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
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
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 36,
                      'char' => 28,
                    ),
                    'name' => 'getOptions',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 36,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 36,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 41,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 41,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 41,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'value',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 41,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 41,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 41,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 41,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 41,
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
                          'value' => 'The option \'value\' is required',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 42,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 42,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 42,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 43,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 48,
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 48,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 48,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'field',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 48,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 48,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 48,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 48,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 48,
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 49,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 49,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 49,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 50,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 55,
              'char' => 13,
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
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 55,
                  'char' => 15,
                ),
                'name' => 'skipOperation',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 55,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 55,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 55,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 60,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'model',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 60,
                    'char' => 18,
                  ),
                  'name' => 'readAttribute',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 60,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 60,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 60,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 60,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 60,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 62,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 64,
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
                  'variable' => 'modelsManager',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 64,
                      'char' => 35,
                    ),
                    'name' => 'getModelsManager',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 64,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 64,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 69,
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
                  'variable' => 'updateModel',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 69,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 69,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 69,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 71,
              'char' => 19,
            ),
            9 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'updateModel',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 71,
                  'char' => 21,
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 71,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 71,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 71,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 71,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 71,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 76,
              'char' => 10,
            ),
            10 => 
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
                    'value' => 'updateModel',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 76,
                    'char' => 25,
                  ),
                  'name' => 'save',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 76,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 76,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'updateModel',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 80,
                      'char' => 40,
                    ),
                    'name' => 'getMessages',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 80,
                    'char' => 55,
                  ),
                  'value' => 'message',
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
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 81,
                          'char' => 23,
                        ),
                        'name' => 'appendMessage',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'message',
                              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                              'line' => 81,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                            'line' => 81,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 81,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 84,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 84,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 90,
              'char' => 13,
            ),
            11 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 90,
                  'char' => 15,
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 90,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 90,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 90,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 90,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 90,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 92,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'modelsManager',
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 92,
                    'char' => 26,
                  ),
                  'name' => 'isKeepingSnapshots',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'model',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 92,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 92,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 92,
                  'char' => 54,
                ),
                'right' => 
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
                        'value' => 'orm.update_snapshot_on_save',
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 92,
                        'char' => 95,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 92,
                      'char' => 95,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 92,
                  'char' => 97,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                'line' => 92,
                'char' => 97,
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 93,
                          'char' => 34,
                        ),
                        'name' => 'getModelsMetaData',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 93,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 93,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 95,
                  'char' => 17,
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
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 95,
                      'char' => 19,
                    ),
                    'name' => 'setSnapshotData',
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
                            'value' => 'updateModel',
                            'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                            'line' => 96,
                            'char' => 29,
                          ),
                          'name' => 'getSnapshotData',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 97,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 97,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 97,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 99,
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
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                      'line' => 99,
                      'char' => 19,
                    ),
                    'name' => 'setOldSnapshotData',
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
                            'value' => 'updateModel',
                            'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                            'line' => 100,
                            'char' => 29,
                          ),
                          'name' => 'getOldSnapshotData',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                          'line' => 101,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                        'line' => 101,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                    'line' => 101,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listens for notifications from the models manager
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
          'line' => 28,
          'last-line' => 104,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior/SoftDelete.zep',
    'line' => 23,
    'char' => 5,
  ),
);