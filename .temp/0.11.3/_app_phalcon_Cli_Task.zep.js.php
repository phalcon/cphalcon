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
    'file' => '/app/phalcon/Cli/Task.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/Task.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Cli/Task.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Cli/Task.zep',
    'line' => 38,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Every command-line task should extend this class that encapsulates all the
 * task functionality
 *
 * A task can be used to run "tasks" such as migrations, cronjobs, unit-tests,
 * or anything that you want. The Task class should at least have a "mainAction"
 * method.
 *
 *```php
 * class HelloTask extends \\Phalcon\\Cli\\Task
 * {
 *     // This action will be executed by default
 *     public function mainAction()
 *     {
 *
 *     }
 *
 *     public function findAction()
 *     {
 *
 *     }
 * }
 *```
 *',
    'file' => '/app/phalcon/Cli/Task.zep',
    'line' => 39,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Task',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'TaskInterface',
        'file' => '/app/phalcon/Cli/Task.zep',
        'line' => 40,
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
          'name' => '__construct',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Cli/Task.zep',
                      'line' => 46,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Cli/Task.zep',
                    'line' => 46,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'onConstruct',
                      'file' => '/app/phalcon/Cli/Task.zep',
                      'line' => 46,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Cli/Task.zep',
                    'line' => 46,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Task.zep',
                'line' => 46,
                'char' => 45,
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
                      'file' => '/app/phalcon/Cli/Task.zep',
                      'line' => 47,
                      'char' => 18,
                    ),
                    'name' => 'onConstruct',
                    'call-type' => 3,
                    'file' => '/app/phalcon/Cli/Task.zep',
                    'line' => 47,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Task.zep',
                  'line' => 48,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Task.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Cli\\Task constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Task.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Task.zep',
          'line' => 44,
          'last-line' => 50,
          'char' => 25,
        ),
      ),
      'file' => '/app/phalcon/Cli/Task.zep',
      'line' => 39,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cli/Task.zep',
    'line' => 39,
    'char' => 5,
  ),
);