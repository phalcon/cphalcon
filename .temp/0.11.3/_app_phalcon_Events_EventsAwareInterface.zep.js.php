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
    'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Events',
    'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Events\\EventsAwareInterface
 *
 * This interface must for those classes that accept an EventsManager and
 * dispatch events
 *',
    'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'EventsAwareInterface',
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
          'name' => 'getEventsManager',
          'docblock' => '**
     * Returns the internal event manager
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
                  'line' => 24,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
                'line' => 24,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
            'line' => 24,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
          'line' => 24,
          'last-line' => 28,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEventsManager',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventsManager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ManagerInterface',
                'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
                'line' => 29,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
              'line' => 29,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Sets the events manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
            'line' => 29,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
          'line' => 29,
          'last-line' => 30,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
      'line' => 30,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Events/EventsAwareInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);