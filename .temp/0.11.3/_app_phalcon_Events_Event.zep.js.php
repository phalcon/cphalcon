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
    'file' => '/app/phalcon/Events/Event.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Events',
    'file' => '/app/phalcon/Events/Event.zep',
    'line' => 18,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Events\\Event
 *
 * This class offers contextual information of a fired event in the
 * EventsManager
 *',
    'file' => '/app/phalcon/Events/Event.zep',
    'line' => 19,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Event',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EventInterface',
        'file' => '/app/phalcon/Events/Event.zep',
        'line' => 20,
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
          'name' => 'cancelable',
          'docblock' => '**
     * Is event cancelable?
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'data',
          'docblock' => '**
     * Event data
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 33,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 39,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'source',
          'docblock' => '**
     * Event source
     *
     * @var object
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 40,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 46,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'stopped',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 47,
            'char' => 30,
          ),
          'docblock' => '**
     * Is event propagation stopped?
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 53,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'docblock' => '**
     * Event type
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 54,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 60,
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
          'name' => '__construct',
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
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 61,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 61,
              'char' => 53,
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
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 61,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 61,
              'char' => 70,
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
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 61,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 61,
              'char' => 94,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 63,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 63,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'source',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'source',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 64,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 64,
                  'char' => 34,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 65,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 65,
                  'char' => 30,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'cancelable',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cancelable',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 66,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 66,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Events\\Event constructor
     *
     * @param object source
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 62,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 61,
          'last-line' => 77,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isCancelable',
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
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 80,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'cancelable',
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 80,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 80,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the event is cancelable.
     *
     * ```php
     * if ($event->isCancelable()) {
     *     $event->stop();
     * }
     * ```
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
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 78,
          'last-line' => 85,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isStopped',
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
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 88,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'stopped',
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 88,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 88,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the event is currently stopped.
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
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 87,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 87,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 86,
          'last-line' => 93,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 94,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 94,
              'char' => 44,
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
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 96,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 96,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 98,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 98,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets event data.
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 95,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 94,
          'last-line' => 103,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setType',
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
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 104,
              'char' => 41,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 106,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 106,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 108,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 108,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 109,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets event type.
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 105,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 104,
          'last-line' => 119,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'stop',
          'statements' => 
          array (
            0 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Events/Event.zep',
                      'line' => 122,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cancelable',
                      'file' => '/app/phalcon/Events/Event.zep',
                      'line' => 122,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 122,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 122,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 122,
                'char' => 39,
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
                          'value' => 'Trying to cancel a non-cancelable event',
                          'file' => '/app/phalcon/Events/Event.zep',
                          'line' => 123,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Events/Event.zep',
                        'line' => 123,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 123,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 124,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 126,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'stopped',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Events/Event.zep',
                    'line' => 126,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 126,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 128,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 128,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Events/Event.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stops the event preventing propagation.
     *
     * ```php
     * if ($event->isCancelable()) {
     *     $event->stop();
     * }
     * ```
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
                  'value' => 'EventInterface',
                  'file' => '/app/phalcon/Events/Event.zep',
                  'line' => 121,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Events/Event.zep',
                'line' => 121,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Events/Event.zep',
            'line' => 121,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Events/Event.zep',
          'line' => 120,
          'last-line' => 130,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Events/Event.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Events/Event.zep',
    'line' => 19,
    'char' => 5,
  ),
);