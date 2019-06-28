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
    'file' => '/app/phalcon/Acl/Adapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Acl',
    'file' => '/app/phalcon/Acl/Adapter.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Acl/Adapter.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Acl/Adapter.zep',
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
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Acl/Adapter.zep',
        'line' => 14,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Acl/Adapter.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Adapter for Phalcon\\Acl adapters
 *',
    'file' => '/app/phalcon/Acl/Adapter.zep',
    'line' => 19,
    'char' => 8,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Adapter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AdapterInterface',
        'file' => '/app/phalcon/Acl/Adapter.zep',
        'line' => 19,
        'char' => 51,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Acl/Adapter.zep',
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
          'name' => 'activeAccess',
          'docblock' => '**
     * Active access which the list is checking if some role can access it
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 26,
              'char' => 34,
            ),
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
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
          'name' => 'accessGranted',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Acl/Adapter.zep',
            'line' => 33,
            'char' => 36,
          ),
          'docblock' => '**
     * Access Granted
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 40,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'activeRole',
          'docblock' => '**
     * Role which the list is checking if it\'s allowed to certain
     * component/access
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 41,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 47,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'activeComponent',
          'docblock' => '**
     * Component which the list is checking if some role can access it
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 48,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 54,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultAccess',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Acl/Adapter.zep',
            'line' => 55,
            'char' => 36,
          ),
          'docblock' => '**
     * Default access
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 61,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'eventsManager',
          'docblock' => '**
     * Events manager
     *
     * @var mixed
     *',
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 66,
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
          'name' => 'getDefaultAction',
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
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 69,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'defaultAccess',
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 69,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Acl/Adapter.zep',
                'line' => 69,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 70,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the default ACL access level
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/Adapter.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/Adapter.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 67,
          'last-line' => 74,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEventsManager',
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
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 77,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 77,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Acl/Adapter.zep',
                'line' => 77,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 78,
              'char' => 5,
            ),
          ),
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
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 76,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Acl/Adapter.zep',
                'line' => 76,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/Adapter.zep',
            'line' => 76,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 75,
          'last-line' => 82,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultAction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultAccess',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 83,
              'char' => 55,
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
                  'property' => 'defaultAccess',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultAccess',
                    'file' => '/app/phalcon/Acl/Adapter.zep',
                    'line' => 85,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 85,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)
     *',
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 83,
          'last-line' => 90,
          'char' => 19,
        ),
        3 => 
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
                'file' => '/app/phalcon/Acl/Adapter.zep',
                'line' => 91,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 91,
              'char' => 70,
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
                  'property' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Acl/Adapter.zep',
                    'line' => 93,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Acl/Adapter.zep',
                  'line' => 93,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Acl/Adapter.zep',
              'line' => 94,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the events manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/Adapter.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Acl/Adapter.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Acl/Adapter.zep',
      'line' => 19,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Acl/Adapter.zep',
    'line' => 19,
    'char' => 14,
  ),
);