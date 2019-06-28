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
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
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
        'name' => 'Phalcon\\Cli\\Dispatcher\\Exception',
        'file' => '/app/phalcon/Cli/Dispatcher.zep',
        'line' => 13,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
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
        'name' => 'Phalcon\\Dispatcher',
        'alias' => 'CliDispatcher',
        'file' => '/app/phalcon/Cli/Dispatcher.zep',
        'line' => 14,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Cli/Dispatcher.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
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
        'name' => 'Phalcon\\Filter\\FilterInterface',
        'file' => '/app/phalcon/Cli/Dispatcher.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
    'line' => 39,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Dispatching is the process of taking the command-line arguments, extracting
 * the module name, task name, action name, and optional parameters contained in
 * it, and then instantiating a task and calling an action on it.
 *
 * ```php
 * use Phalcon\\Di;
 * use Phalcon\\Cli\\Dispatcher;
 *
 * $di = new Di();
 *
 * $dispatcher = new Dispatcher();
 *
 * $dispatcher->setDi($di);
 *
 * $dispatcher->setTaskName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $handle = $dispatcher->dispatch();
 * ```
 *',
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
    'line' => 40,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Dispatcher',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'CliDispatcher',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'DispatcherInterface',
        'file' => '/app/phalcon/Cli/Dispatcher.zep',
        'line' => 41,
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
          'name' => 'defaultHandler',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'main',
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 45,
            'char' => 36,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 49,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultAction',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'main',
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 50,
            'char' => 35,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 54,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'handlerSuffix',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Task',
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 55,
            'char' => 35,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 59,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 60,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 64,
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
          'name' => 'callActionMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 65,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'actionMethod',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 65,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 65,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 67,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 71,
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
                  'variable' => 'params',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_values',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 71,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 71,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 71,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 71,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 72,
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
                  'variable' => 'params',
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 72,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 72,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 72,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 72,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 72,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 72,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 72,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 72,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 74,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
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
                      'type' => 'array',
                      'left' => 
                      array (
                        0 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handler',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 75,
                            'char' => 21,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 75,
                          'char' => 21,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'actionMethod',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 75,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 75,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 75,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 75,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 77,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 77,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 77,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 78,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calls the action method.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 65,
          'last-line' => 82,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveTask',
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 85,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeHandler',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 85,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 85,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the active task in the dispatcher
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
                  'value' => 'TaskInterface',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 84,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 84,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 84,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 83,
          'last-line' => 90,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastTask',
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 93,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'lastHandler',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 93,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 93,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 94,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the latest dispatched controller
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
                  'value' => 'TaskInterface',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 92,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 92,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 91,
          'last-line' => 102,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 103,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 103,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 103,
              'char' => 53,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 103,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 103,
              'char' => 74,
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 105,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'filter',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 105,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'optionValue',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 105,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 105,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 107,
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
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 107,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 107,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 107,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 107,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 109,
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
                    'value' => 'optionValue',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 109,
                    'char' => 48,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 109,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'option',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 109,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 109,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 109,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 109,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 110,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 111,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 113,
              'char' => 10,
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
                  'value' => 'filters',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 113,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 113,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 113,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'optionValue',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 114,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 117,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 117,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 117,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 117,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 117,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 119,
              'char' => 10,
            ),
            5 => 
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
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 119,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 119,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 119,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 119,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 120,
                      'char' => 18,
                    ),
                    'name' => 'throwDispatchException',
                    'call-type' => 3,
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
                                'value' => 'the \'filter\' service',
                                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                                'line' => 121,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Cli/Dispatcher.zep',
                              'line' => 121,
                              'char' => 73,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 121,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 121,
                        'char' => 74,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'CliDispatcher',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 123,
                            'char' => 13,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EXCEPTION_NO_DI',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 123,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 123,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 123,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 123,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 124,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 126,
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
                  'variable' => 'filter',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'FilterInterface',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 126,
                      'char' => 68,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 126,
                        'char' => 50,
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
                            'value' => 'filter',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 126,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 126,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 126,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 126,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 126,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 128,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'filter',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 128,
                  'char' => 23,
                ),
                'name' => 'sanitize',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'optionValue',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 128,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 128,
                    'char' => 44,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 128,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 128,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 128,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets an option by its name or numeric index
     *
     * @param  mixed $option
     * @param  string|array $filters
     * @param  mixed $defaultValue
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 104,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 104,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 103,
          'last-line' => 133,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 136,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'options',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 136,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 136,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get dispatched options
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
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 134,
          'last-line' => 141,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTaskName',
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 144,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handlerName',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 144,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 144,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets last dispatched task name
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
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 143,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 143,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 142,
          'last-line' => 149,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTaskSuffix',
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
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 152,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handlerSuffix',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 152,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 152,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the default task suffix
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
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 151,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 150,
          'last-line' => 157,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 158,
              'char' => 41,
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
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 160,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 160,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 160,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'option',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 160,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 160,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 160,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if an option exists
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
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 159,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 158,
          'last-line' => 165,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultTask',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'taskName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 166,
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
                  'property' => 'defaultHandler',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'taskName',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 168,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 168,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 169,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default task name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 167,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 166,
          'last-line' => 173,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOptions',
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
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 174,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 176,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 176,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 177,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the options to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 174,
          'last-line' => 181,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTaskName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'taskName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 182,
              'char' => 48,
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
                  'property' => 'handlerName',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'taskName',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 184,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 184,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 185,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the task name to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 183,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 182,
          'last-line' => 189,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTaskSuffix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'taskSuffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 190,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handlerSuffix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'taskSuffix',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 192,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 192,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 193,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default task suffix
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Dispatcher.zep',
            'line' => 191,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 190,
          'last-line' => 197,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'exception',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Exception',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 198,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 198,
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
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 200,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 202,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 202,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 202,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 202,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 202,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 202,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 202,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 204,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 204,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 204,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 204,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 204,
                'char' => 43,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 205,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'dispatch:beforeException',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 205,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 205,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 205,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 205,
                          'char' => 66,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'exception',
                            'file' => '/app/phalcon/Cli/Dispatcher.zep',
                            'line' => 205,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 205,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 205,
                      'char' => 81,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 205,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 205,
                    'char' => 89,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 206,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 207,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 209,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles a user exception
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 198,
          'last-line' => 213,
          'char' => 22,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'throwDispatchException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 214,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'exceptionCode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 214,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 214,
              'char' => 84,
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
                  'variable' => 'exception',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 216,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 218,
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
                  'variable' => 'exception',
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
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 218,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 218,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'exceptionCode',
                          'file' => '/app/phalcon/Cli/Dispatcher.zep',
                          'line' => 218,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 218,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 218,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 218,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 220,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'this',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 220,
                    'char' => 17,
                  ),
                  'name' => 'handleException',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Cli/Dispatcher.zep',
                        'line' => 220,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Cli/Dispatcher.zep',
                      'line' => 220,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 220,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 220,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 220,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Cli/Dispatcher.zep',
                    'line' => 221,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Cli/Dispatcher.zep',
                  'line' => 222,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 224,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'exception',
                'file' => '/app/phalcon/Cli/Dispatcher.zep',
                'line' => 224,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Cli/Dispatcher.zep',
              'line' => 225,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an internal exception
     *',
          'file' => '/app/phalcon/Cli/Dispatcher.zep',
          'line' => 214,
          'last-line' => 226,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Cli/Dispatcher.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cli/Dispatcher.zep',
    'line' => 40,
    'char' => 5,
  ),
);