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
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\BehaviorInterface',
        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
        'line' => 14,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Behavior
 *
 * This is an optional base class for ORM behaviors
 *',
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
    'line' => 21,
    'char' => 8,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Behavior',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'BehaviorInterface',
        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
        'line' => 22,
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
          'name' => 'options',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 30,
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 31,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 31,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 33,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 33,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 34,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Behavior
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 31,
          'last-line' => 40,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 41,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 41,
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
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 43,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'eventOptions',
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 43,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 45,
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
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 45,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 45,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 45,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 45,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 47,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventName',
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 47,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 47,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 47,
                'char' => 31,
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
                      'type' => 'fetch',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventOptions',
                        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                        'line' => 48,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                          'line' => 48,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventName',
                          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                          'line' => 48,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                        'line' => 48,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 48,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 48,
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
                        'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                        'line' => 49,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 50,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 52,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventOptions',
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 52,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 55,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'options',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 55,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 56,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the behavior options related to an event
     *
     * @return array
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 41,
          'last-line' => 60,
          'char' => 22,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'missingMethod',
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
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 61,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 61,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 61,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 61,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 61,
              'char' => 94,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 63,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Acts as fallbacks when a missing method is called on the model
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 61,
          'last-line' => 68,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'mustTakeAction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 69,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 71,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                      'line' => 71,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 71,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventName',
                    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                    'line' => 71,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                  'line' => 71,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 71,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 72,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether the behavior must take action on certain event
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
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 69,
          'last-line' => 76,
          'char' => 22,
        ),
        4 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 77,
              'char' => 39,
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
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 77,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 77,
              'char' => 63,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
                'line' => 79,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * This method receives the notifications from the EventsManager
     *',
          'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
          'line' => 77,
          'last-line' => 81,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
      'line' => 21,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/Model/Behavior.zep',
    'line' => 21,
    'char' => 14,
  ),
);