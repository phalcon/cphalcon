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
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Collection',
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Db\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
        'line' => 13,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\CollectionInterface',
        'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
        'line' => 14,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Collection\\BehaviorInterface',
        'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
        'line' => 15,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'alias' => 'EventsManagerInterface',
        'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
        'line' => 16,
        'char' => 62,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
    'line' => 38,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Collection\\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\\Di.
 *
 * ```php
 * $di = new \\Phalcon\\Di();
 *
 * $di->set(
 *     "collectionManager",
 *     function() {
 *         return new \\Phalcon\\Mvc\\Collection\\Manager();
 *     }
 * );
 *
 * $robot = new Robots(di);
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
    'line' => 39,
    'char' => 9,
  ),
  7 => 
  array (
    'type' => 'interface',
    'name' => 'ManagerInterface',
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
          'name' => 'addBehavior',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 44,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 44,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'behavior',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'BehaviorInterface',
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 44,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 44,
              'char' => 90,
            ),
          ),
          'docblock' => '**
     * Binds a behavior to a collection
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConnection',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 49,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 49,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Returns the connection related to a model
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                  'line' => 49,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 49,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
            'line' => 49,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 49,
          'last-line' => 53,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCustomEventsManager',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 54,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 54,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Returns a custom events manager related to a model
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
                  'value' => 'EventsManagerInterface',
                  'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                  'line' => 54,
                  'char' => 100,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 54,
                'char' => 100,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
            'line' => 54,
            'char' => 100,
          ),
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 54,
          'last-line' => 58,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastInitialized',
          'docblock' => '**
     * Get the latest initialized model
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                  'line' => 59,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 59,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
            'line' => 59,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 59,
          'last-line' => 63,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'initialize',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 64,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 64,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Initializes a model in the models manager
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 64,
          'last-line' => 68,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isInitialized',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 69,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Check whether a model is already initialized
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 69,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
            'line' => 69,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 69,
          'last-line' => 73,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingImplicitObjectIds',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 74,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 74,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Checks if a model is using implicit object ids
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 74,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
            'line' => 74,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 74,
          'last-line' => 79,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyEvent',
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
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 80,
              'char' => 50,
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 80,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 80,
              'char' => 79,
            ),
          ),
          'docblock' => '**
     * Receives events generated in the models and dispatches them to an events-manager if available
     * Notify the behaviors that are listening in the model
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 80,
          'last-line' => 84,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCustomEventsManager',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 85,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 85,
              'char' => 71,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'eventsManager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'EventsManagerInterface',
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 85,
                'char' => 110,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 85,
              'char' => 111,
            ),
          ),
          'docblock' => '**
     * Sets a custom events manager for a specific model
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 85,
          'last-line' => 89,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setConnectionService',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 90,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 90,
              'char' => 69,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 90,
              'char' => 96,
            ),
          ),
          'docblock' => '**
     * Sets a connection service for a specific model
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 90,
          'last-line' => 94,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useImplicitObjectIds',
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
                'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
                'line' => 95,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 95,
              'char' => 69,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'useImplicitObjectIds',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
              'line' => 95,
              'char' => 96,
            ),
          ),
          'docblock' => '**
     * Sets if a model must use implicit objects ids
     *',
          'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
          'line' => 95,
          'last-line' => 96,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
      'line' => 96,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Collection/ManagerInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);