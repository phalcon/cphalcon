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
    'file' => '/app/phalcon/Events/ManagerInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Events',
    'file' => '/app/phalcon/Events/ManagerInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  2 => 
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
    'file' => '/app/phalcon/Events/ManagerInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  3 => 
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 28,
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 28,
              'char' => 54,
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
            'file' => '/app/phalcon/Events/ManagerInterface.zep',
            'line' => 28,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 28,
          'last-line' => 34,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 35,
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 35,
              'char' => 54,
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
            'file' => '/app/phalcon/Events/ManagerInterface.zep',
            'line' => 35,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 35,
          'last-line' => 39,
          'char' => 19,
        ),
        2 => 
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
                'file' => '/app/phalcon/Events/ManagerInterface.zep',
                'line' => 40,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 40,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Removes all events from the EventsManager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/ManagerInterface.zep',
            'line' => 40,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 40,
          'last-line' => 49,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 50,
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 50,
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
                'file' => '/app/phalcon/Events/ManagerInterface.zep',
                'line' => 50,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 50,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Fires an event in the events manager causing the active listeners to be
     * notified about it
     *
     * @param object source
     * @param mixed  data
     * @return mixed
     *',
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 55,
              'char' => 46,
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
                'file' => '/app/phalcon/Events/ManagerInterface.zep',
                'line' => 55,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/ManagerInterface.zep',
            'line' => 55,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 55,
          'last-line' => 59,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Events/ManagerInterface.zep',
              'line' => 60,
              'char' => 46,
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
                'file' => '/app/phalcon/Events/ManagerInterface.zep',
                'line' => 60,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/ManagerInterface.zep',
            'line' => 60,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Events/ManagerInterface.zep',
          'line' => 60,
          'last-line' => 61,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Events/ManagerInterface.zep',
      'line' => 61,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Events/ManagerInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);