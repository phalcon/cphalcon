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
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ControllerInterface',
        'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
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
        'name' => 'Phalcon\\DispatcherInterface',
        'alias' => 'DispatcherInterfaceBase',
        'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
        'line' => 14,
        'char' => 59,
      ),
    ),
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\DispatcherInterface
 *
 * Interface for Phalcon\\Mvc\\Dispatcher
 *',
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'DispatcherInterface',
    'extends' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'DispatcherInterfaceBase',
        'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
        'line' => 22,
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
          'name' => 'getActiveController',
          'docblock' => '**
     * Returns the active controller in the dispatcher
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
                  'value' => 'ControllerInterface',
                  'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
                  'line' => 26,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
                'line' => 26,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
            'line' => 26,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerName',
          'docblock' => '**
     * Gets last dispatched controller name
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
                'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
                'line' => 31,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
            'line' => 31,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastController',
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
                  'value' => 'ControllerInterface',
                  'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
                  'line' => 36,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
                'line' => 36,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
            'line' => 36,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setControllerSuffix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerSuffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
              'line' => 41,
              'char' => 65,
            ),
          ),
          'docblock' => '**
     * Sets the default controller suffix
     *',
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setControllerName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
              'line' => 46,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Sets the controller name to be dispatched
     *',
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultController',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
              'line' => 51,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Sets the default controller name
     *',
          'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
          'line' => 51,
          'last-line' => 52,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
      'line' => 52,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/DispatcherInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);