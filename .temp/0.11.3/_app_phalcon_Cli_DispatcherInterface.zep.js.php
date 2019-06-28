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
    'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
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
        'name' => 'Phalcon\\DispatcherInterface',
        'alias' => 'DispatcherInterfaceBase',
        'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
        'line' => 13,
        'char' => 59,
      ),
    ),
    'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Cli\\Dispatcher
 *',
    'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'DispatcherInterface',
    'extends' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'DispatcherInterfaceBase',
        'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
        'line' => 19,
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
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveTask',
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
                  'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                  'line' => 23,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                'line' => 23,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 23,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastTask',
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
                  'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                  'line' => 28,
                  'char' => 53,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                'line' => 28,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 28,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
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
                'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                'line' => 33,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 33,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTaskName',
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
                'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                'line' => 38,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 38,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTaskSuffix',
          'docblock' => '**
     * Gets default task suffix
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
                'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
                'line' => 43,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 43,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
              'line' => 48,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets the default task name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 48,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
              'line' => 53,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Set the options to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 53,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        7 => 
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
              'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
              'line' => 58,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Sets the task name to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 58,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
              'line' => 63,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the default task suffix
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
            'line' => 63,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
          'line' => 63,
          'last-line' => 64,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
      'line' => 64,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Cli/DispatcherInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);