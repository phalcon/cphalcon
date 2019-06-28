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
    'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Collection',
    'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Collection\\BehaviorInterface
 *
 * Interface for Phalcon\\Mvc\\Collection\\Behavior
 *',
    'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
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
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
                'line' => 25,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
              'line' => 25,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
              'line' => 25,
              'char' => 83,
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
                'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
                'line' => 25,
                'char' => 105,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
              'line' => 25,
              'char' => 105,
            ),
          ),
          'docblock' => '**
     * Calls a method when it\'s missing in the collection
     *',
          'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
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
              'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
              'line' => 30,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
                'line' => 30,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
              'line' => 30,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * This method receives the notifications from the EventsManager
     *',
          'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
          'line' => 30,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
      'line' => 31,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Collection/BehaviorInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);