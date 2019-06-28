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
    'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\BehaviorInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Behavior
 *',
    'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'BehaviorInterface',
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
                'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
                'line' => 25,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
              'line' => 25,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
              'line' => 25,
              'char' => 73,
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
                'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
                'line' => 25,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
              'line' => 25,
              'char' => 95,
            ),
          ),
          'docblock' => '**
     * Calls a method when it\'s missing in the model
     *',
          'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
              'line' => 30,
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
                'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
                'line' => 30,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
              'line' => 30,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * This method receives the notifications from the EventsManager
     *',
          'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
          'line' => 30,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
      'line' => 31,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/BehaviorInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);