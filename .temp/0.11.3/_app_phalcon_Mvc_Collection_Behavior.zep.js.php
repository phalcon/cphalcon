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
    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Collection',
    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
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
        'name' => 'Phalcon\\Mvc\\CollectionInterface',
        'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Collection\\Behavior
 *
 * This is an optional base class for ORM behaviors
 *',
    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
    'line' => 20,
    'char' => 8,
  ),
  4 => 
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
        'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
        'line' => 21,
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
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 26,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 27,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 27,
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
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 29,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 29,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 30,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Collection\\Behavior
     *',
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 27,
          'last-line' => 36,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 37,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 37,
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
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 39,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'eventOptions',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 39,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 41,
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
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 41,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 41,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 41,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 41,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 42,
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
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 42,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 42,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 42,
                'char' => 31,
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
                      'value' => 'eventOptions',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 43,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                        'line' => 43,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventName',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                        'line' => 43,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 43,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 43,
                    'char' => 55,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventOptions',
                        'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                        'line' => 44,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 45,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 46,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 46,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 47,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 48,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'options',
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 48,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the behavior options related to an event
     *
     * @return array
     *',
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 37,
          'last-line' => 53,
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
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 54,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 54,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 54,
              'char' => 77,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 54,
                'char' => 99,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 54,
              'char' => 99,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 56,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Acts as fallbacks when a missing method is called on the collection
     *',
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 54,
          'last-line' => 61,
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
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 62,
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
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 64,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                      'line' => 64,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 64,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventName',
                    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                    'line' => 64,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                  'line' => 64,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 64,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 65,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 62,
          'last-line' => 69,
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
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 70,
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
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 70,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 70,
              'char' => 68,
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
                'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
                'line' => 72,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * This method receives the notifications from the EventsManager
     *',
          'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
          'line' => 70,
          'last-line' => 74,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
      'line' => 20,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/Collection/Behavior.zep',
    'line' => 20,
    'char' => 14,
  ),
);