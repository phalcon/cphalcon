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
    'file' => '/app/phalcon/Events/Manager.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Events',
    'file' => '/app/phalcon/Events/Manager.zep',
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
        'file' => '/app/phalcon/Events/Manager.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Events/Manager.zep',
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
        'name' => 'Phalcon\\Events\\Event',
        'file' => '/app/phalcon/Events/Manager.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Events/Manager.zep',
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
        'name' => 'SplPriorityQueue',
        'file' => '/app/phalcon/Events/Manager.zep',
        'line' => 15,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Events/Manager.zep',
    'line' => 24,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Events\\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if
 * needed, the normal flow of operation. With the EventsManager the developer
 * can create hooks or plugins that will offer monitoring of data, manipulation,
 * conditional execution and much more.
 *',
    'file' => '/app/phalcon/Events/Manager.zep',
    'line' => 25,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Manager',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ManagerInterface',
        'file' => '/app/phalcon/Events/Manager.zep',
        'line' => 26,
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
          'name' => 'collect',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 32,
            'char' => 30,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 36,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'enablePriorities',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 37,
            'char' => 39,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 39,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'events',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 39,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 41,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'responses',
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 47,
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
          'name' => 'attach',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventType',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 48,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 48,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'priority',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 48,
                  'char' => 98,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'DEFAULT_PRIORITY',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 48,
                  'char' => 98,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 48,
                'char' => 98,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 48,
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
                  'variable' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 50,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 52,
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
                      'value' => 'handler',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 52,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 52,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 52,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 52,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 52,
                'char' => 46,
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
                          'value' => 'Event handler must be an Object',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 53,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 53,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 53,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 54,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 56,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'priorityQueue',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 56,
                    'char' => 58,
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
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 56,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'events',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 56,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 56,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventType',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 56,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 56,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 56,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 56,
                'char' => 58,
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
                      'variable' => 'priorityQueue',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'SplPriorityQueue',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 58,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 58,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 61,
                  'char' => 25,
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
                      'value' => 'priorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 61,
                      'char' => 27,
                    ),
                    'name' => 'setExtractFlags',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SplPriorityQueue',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 63,
                            'char' => 13,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EXTR_DATA',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 63,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 63,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 63,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 63,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 66,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'events',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventType',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 66,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'priorityQueue',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 66,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 66,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 69,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 69,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'enablePriorities',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 69,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 69,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 69,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'priority',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 70,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'DEFAULT_PRIORITY',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 70,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 70,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 70,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 71,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 74,
              'char' => 21,
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
                  'value' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 74,
                  'char' => 23,
                ),
                'name' => 'insert',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 74,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 74,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'priority',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 74,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 74,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 74,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Attach a listener to the events manager
     *
     * @param object|callable handler
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 49,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 48,
          'last-line' => 79,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'arePrioritiesEnabled',
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
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 82,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'enablePriorities',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 82,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 82,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns if priorities are enabled
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
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 80,
          'last-line' => 88,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'collectResponses',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collect',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 89,
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
                  'property' => 'collect',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collect',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 91,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 91,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Tells the event manager if it needs to collect all the responses returned
     * by every registered listener in a single fire
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 89,
          'last-line' => 98,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'detach',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventType',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 99,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 99,
              'char' => 58,
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
                  'variable' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 101,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'newPriorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 101,
                  'char' => 44,
                ),
                2 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 101,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 103,
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
                      'value' => 'handler',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 103,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 103,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 103,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 103,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 103,
                'char' => 46,
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
                          'value' => 'Event handler must be an Object',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 104,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 104,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 104,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 107,
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
                  'value' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 107,
                  'char' => 57,
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
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 107,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'events',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 107,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 107,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventType',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 107,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 107,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 107,
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
                      'variable' => 'newPriorityQueue',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'SplPriorityQueue',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 112,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 112,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 114,
                  'char' => 28,
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
                      'value' => 'newPriorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 114,
                      'char' => 30,
                    ),
                    'name' => 'setExtractFlags',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SplPriorityQueue',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 116,
                            'char' => 13,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EXTR_DATA',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 116,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 116,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 116,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 116,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 118,
                  'char' => 25,
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
                      'value' => 'priorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 118,
                      'char' => 27,
                    ),
                    'name' => 'setExtractFlags',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SplPriorityQueue',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 120,
                            'char' => 13,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EXTR_BOTH',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 120,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 120,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 120,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 120,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 122,
                  'char' => 25,
                ),
                3 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'priorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 122,
                      'char' => 27,
                    ),
                    'name' => 'top',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 122,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 124,
                  'char' => 17,
                ),
                4 => 
                array (
                  'type' => 'while',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'priorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 124,
                      'char' => 33,
                    ),
                    'name' => 'valid',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 124,
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
                          'variable' => 'data',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'priorityQueue',
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 125,
                              'char' => 42,
                            ),
                            'name' => 'current',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 125,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 125,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 127,
                      'char' => 29,
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
                          'value' => 'priorityQueue',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 127,
                          'char' => 31,
                        ),
                        'name' => 'next',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 127,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 129,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 129,
                            'char' => 24,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'data',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 129,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 129,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 129,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 129,
                        'char' => 43,
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
                              'value' => 'newPriorityQueue',
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 130,
                              'char' => 38,
                            ),
                            'name' => 'insert',
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
                                    'value' => 'data',
                                    'file' => '/app/phalcon/Events/Manager.zep',
                                    'line' => 131,
                                    'char' => 29,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'data',
                                    'file' => '/app/phalcon/Events/Manager.zep',
                                    'line' => 131,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 131,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 131,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'data',
                                    'file' => '/app/phalcon/Events/Manager.zep',
                                    'line' => 132,
                                    'char' => 29,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'priority',
                                    'file' => '/app/phalcon/Events/Manager.zep',
                                    'line' => 132,
                                    'char' => 38,
                                  ),
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 133,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 133,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 133,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 134,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 135,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 137,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'events',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventType',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 137,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'newPriorityQueue',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 137,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 137,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 138,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 139,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Detach the listener from the events manager
     *
     * @param object handler
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 100,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 99,
          'last-line' => 143,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'detachAll',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 144,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 144,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'type',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 146,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 146,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 146,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'events',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 147,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 147,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 148,
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
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 149,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'events',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 149,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 149,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 149,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 149,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 149,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'unset',
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
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 150,
                            'char' => 28,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'events',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 150,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 150,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 150,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 150,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 151,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 152,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes all events from the EventsManager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 145,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 144,
          'last-line' => 157,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'enablePriorities',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'enablePriorities',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 158,
              'char' => 59,
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
                  'property' => 'enablePriorities',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'enablePriorities',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 160,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 160,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set if priorities are enabled in the EventsManager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 158,
          'last-line' => 174,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fire',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventType',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 175,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 175,
              'char' => 51,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 175,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 175,
              'char' => 64,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'cancelable',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 175,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 175,
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
                  'variable' => 'events',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'eventParts',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 37,
                ),
                3 => 
                array (
                  'variable' => 'eventName',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'event',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'status',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 63,
                ),
                6 => 
                array (
                  'variable' => 'fireEvents',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 177,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 179,
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
                  'variable' => 'events',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 179,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'events',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 179,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 179,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 179,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 181,
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
                    'value' => 'events',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 181,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 181,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 181,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 181,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 182,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 183,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 186,
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
                          'value' => 'eventType',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 186,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 186,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 186,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 186,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 186,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 186,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 186,
                'char' => 43,
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
                            'value' => 'Invalid event type ',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 187,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventType',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 187,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 187,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 187,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 187,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventParts',
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
                          'value' => ':',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 190,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 190,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventType',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 190,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 190,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 190,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 190,
                  'char' => 47,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'type',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventParts',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 191,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 191,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 191,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 191,
                  'char' => 33,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventName',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventParts',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 192,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 192,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 192,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 192,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 194,
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
                  'variable' => 'status',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 194,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 194,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 197,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 197,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'collect',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 197,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 197,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'responses',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 198,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 198,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 199,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 202,
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
                  'variable' => 'event',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Event',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventName',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 202,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 202,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'source',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 202,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 202,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 202,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 202,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cancelable',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 202,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 202,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 202,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 202,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 205,
              'char' => 10,
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
                  'value' => 'fireEvents',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 205,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'events',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 205,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 205,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 205,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 205,
                'char' => 43,
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
                        'value' => 'fireEvents',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 206,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 206,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 206,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 206,
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
                          'variable' => 'status',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 208,
                              'char' => 35,
                            ),
                            'name' => 'fireQueue',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fireEvents',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 208,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 208,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'event',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 208,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 208,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 208,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 208,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 209,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 210,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 213,
              'char' => 10,
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
                  'value' => 'fireEvents',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 213,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'events',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 213,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventType',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 213,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 213,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 213,
                'char' => 48,
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
                        'value' => 'fireEvents',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 214,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 214,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 214,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 214,
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
                          'variable' => 'status',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 216,
                              'char' => 35,
                            ),
                            'name' => 'fireQueue',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fireEvents',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 216,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 216,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'event',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 216,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 216,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 216,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 216,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 217,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 218,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 220,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'status',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 220,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 221,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Fires an event in the events manager causing the active listeners to be
     * notified about it
     *
     *```php
     * $eventsManager->fire("db", $connection);
     *```
     *
     * @param object source
     * @param mixed  data
     * @return mixed
     *',
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 175,
          'last-line' => 227,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'fireQueue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'queue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'SplPriorityQueue',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 228,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 228,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'event',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'EventInterface',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 228,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 228,
              'char' => 85,
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
                  'variable' => 'status',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'eventName',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'iterator',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 46,
                ),
                4 => 
                array (
                  'variable' => 'source',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 54,
                ),
                5 => 
                array (
                  'variable' => 'handler',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 230,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 231,
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
                  'variable' => 'collect',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 231,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'cancelable',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 231,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 233,
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
                  'variable' => 'status',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 233,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 233,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 236,
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
                  'variable' => 'eventName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'event',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 236,
                      'char' => 31,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 236,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 236,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 238,
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
                      'value' => 'eventName',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 238,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 238,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 238,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 238,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 238,
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
                          'value' => 'The event type not valid',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 239,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 239,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 239,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 240,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 243,
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
                  'variable' => 'source',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'event',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 243,
                      'char' => 28,
                    ),
                    'name' => 'getSource',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 243,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 243,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 246,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'event',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 246,
                      'char' => 26,
                    ),
                    'name' => 'getData',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 246,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 246,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 249,
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
                  'variable' => 'cancelable',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'event',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 249,
                        'char' => 39,
                      ),
                      'name' => 'isCancelable',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 249,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 249,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 249,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 252,
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
                  'variable' => 'collect',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 252,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collect',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 252,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 252,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 252,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 252,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 255,
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
                  'variable' => 'iterator',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'queue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 255,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 255,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 255,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 258,
              'char' => 16,
            ),
            10 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'iterator',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 258,
                  'char' => 18,
                ),
                'name' => 'top',
                'call-type' => 1,
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 258,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 260,
              'char' => 13,
            ),
            11 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'iterator',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 260,
                  'char' => 24,
                ),
                'name' => 'valid',
                'call-type' => 1,
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 260,
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
                      'variable' => 'handler',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'iterator',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 262,
                          'char' => 36,
                        ),
                        'name' => 'current',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 262,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 262,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 264,
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
                      'value' => 'iterator',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 264,
                      'char' => 22,
                    ),
                    'name' => 'next',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 264,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 267,
                  'char' => 14,
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
                          'value' => 'handler',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 267,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 267,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 267,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 267,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 267,
                    'char' => 50,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 269,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 272,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 272,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Closure',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 272,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 272,
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
                          'variable' => 'status',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'call_user_func_array',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'handler',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 275,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 275,
                                'char' => 28,
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
                                        'value' => 'event',
                                        'file' => '/app/phalcon/Events/Manager.zep',
                                        'line' => 276,
                                        'char' => 27,
                                      ),
                                      'file' => '/app/phalcon/Events/Manager.zep',
                                      'line' => 276,
                                      'char' => 27,
                                    ),
                                    1 => 
                                    array (
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'source',
                                        'file' => '/app/phalcon/Events/Manager.zep',
                                        'line' => 276,
                                        'char' => 35,
                                      ),
                                      'file' => '/app/phalcon/Events/Manager.zep',
                                      'line' => 276,
                                      'char' => 35,
                                    ),
                                    2 => 
                                    array (
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'data',
                                        'file' => '/app/phalcon/Events/Manager.zep',
                                        'line' => 276,
                                        'char' => 41,
                                      ),
                                      'file' => '/app/phalcon/Events/Manager.zep',
                                      'line' => 276,
                                      'char' => 41,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 277,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 277,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 277,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 277,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 278,
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
                        'type' => 'not',
                        'left' => 
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
                                'value' => 'handler',
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 280,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 280,
                              'char' => 42,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'eventName',
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 280,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 280,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 280,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 280,
                        'char' => 55,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 282,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 284,
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
                          'variable' => 'status',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handler',
                              'file' => '/app/phalcon/Events/Manager.zep',
                              'line' => 284,
                              'char' => 38,
                            ),
                            'name' => 'eventName',
                            'call-type' => 2,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'event',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 284,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 284,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'source',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 284,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 284,
                                'char' => 64,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'data',
                                  'file' => '/app/phalcon/Events/Manager.zep',
                                  'line' => 284,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Events/Manager.zep',
                                'line' => 284,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 284,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 284,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 285,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 288,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collect',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 288,
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
                          'assign-type' => 'object-property-append',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'responses',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'status',
                            'file' => '/app/phalcon/Events/Manager.zep',
                            'line' => 289,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 289,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 290,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 292,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cancelable',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 292,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'event',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 294,
                          'char' => 26,
                        ),
                        'name' => 'isStopped',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 294,
                        'char' => 39,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 296,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 297,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 298,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 300,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'status',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 300,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 301,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internal handler to call a queue of events
     *
     * @return mixed
     *',
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 228,
          'last-line' => 305,
          'char' => 25,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getListeners',
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
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 306,
              'char' => 46,
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
                  'variable' => 'fireEvents',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 308,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 308,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 309,
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
                  'variable' => 'listeners',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 309,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 311,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'fireEvents',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 311,
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
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 311,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'events',
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 311,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 311,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 311,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 311,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 311,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 311,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 312,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 313,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 315,
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
                  'variable' => 'listeners',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 315,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 315,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 317,
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
                  'variable' => 'priorityQueue',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fireEvents',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 317,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 317,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 317,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 319,
              'char' => 21,
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
                  'value' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 319,
                  'char' => 23,
                ),
                'name' => 'top',
                'call-type' => 1,
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 319,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 321,
              'char' => 13,
            ),
            6 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'priorityQueue',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 321,
                  'char' => 29,
                ),
                'name' => 'valid',
                'call-type' => 1,
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 321,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'listeners',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'priorityQueue',
                          'file' => '/app/phalcon/Events/Manager.zep',
                          'line' => 322,
                          'char' => 45,
                        ),
                        'name' => 'current',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Events/Manager.zep',
                        'line' => 322,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 322,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 324,
                  'char' => 25,
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
                      'value' => 'priorityQueue',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 324,
                      'char' => 27,
                    ),
                    'name' => 'next',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 324,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 325,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 327,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'listeners',
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 327,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 328,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the attached listeners of a certain type
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
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 307,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 307,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 306,
          'last-line' => 333,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getResponses',
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
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 336,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'responses',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 336,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 336,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 337,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the responses returned by every handler executed by the last
     * \'fire\' executed
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
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 335,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 335,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 334,
          'last-line' => 341,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasListeners',
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
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 342,
              'char' => 46,
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
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 344,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'events',
                      'file' => '/app/phalcon/Events/Manager.zep',
                      'line' => 344,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 344,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Events/Manager.zep',
                    'line' => 344,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 344,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 344,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 345,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether certain type of event has listeners
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
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 343,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 343,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 342,
          'last-line' => 350,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isCollecting',
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
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 353,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'collect',
                  'file' => '/app/phalcon/Events/Manager.zep',
                  'line' => 353,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 353,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Events/Manager.zep',
              'line' => 354,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the events manager is collecting all all the responses returned
     * by every registered listener in a single fire
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
                'file' => '/app/phalcon/Events/Manager.zep',
                'line' => 352,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 352,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 351,
          'last-line' => 355,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'DEFAULT_PRIORITY',
          'default' => 
          array (
            'type' => 'int',
            'value' => '100',
            'file' => '/app/phalcon/Events/Manager.zep',
            'line' => 27,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Events/Manager.zep',
          'line' => 31,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Events/Manager.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Events/Manager.zep',
    'line' => 25,
    'char' => 5,
  ),
);