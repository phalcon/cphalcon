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
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Firewall',
    'file' => '/app/phalcon/Firewall/Adapter.zep',
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
        'name' => 'Closure',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
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
        'name' => 'Phalcon\\Acl',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 14,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
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
        'name' => 'Phalcon\\Acl\\RoleAware',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'alias' => 'CacheAdapterInterface',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 16,
        'char' => 68,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 17,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 18,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 19,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Dispatcher',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 20,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 24,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Adapter for Phalcon\\Firewall adapters
 *',
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 25,
    'char' => 8,
  ),
  11 => 
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
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 25,
        'char' => 51,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Firewall/Adapter.zep',
        'line' => 26,
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
          'name' => 'activeIdentity',
          'docblock' => '**
     * Storing active identity object implementing Phalcon/Acl/RoleAware
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 30,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 34,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'activeRole',
          'docblock' => '**
     * Storing active user role
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 35,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
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
          'name' => 'alwaysResolvingRole',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 41,
            'char' => 43,
          ),
          'docblock' => '**
     * Should role always be resolved using role callback or just once?
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 41,
              'char' => 49,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
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
          'name' => 'cache',
          'docblock' => '**
     * Cache for caching access
     * @var <CacheAdapterInterface>
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 52,
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
            'type' => 'static-constant-access',
            'left' => 
            array (
              'type' => 'variable',
              'value' => 'Acl',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 53,
              'char' => 41,
            ),
            'right' => 
            array (
              'type' => 'variable',
              'value' => 'DENY',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 53,
              'char' => 41,
            ),
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 53,
            'char' => 41,
          ),
          'docblock' => '**
     * Default access
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 53,
              'char' => 47,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 58,
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
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 64,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'internalCache',
          'docblock' => '**
     * Internal cache for caching access during request time
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 71,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'roleCallback',
          'docblock' => '**
     * Anonymous function for getting user identity - this function must
     * return string, array or object implementing Phalcon\\Acl\\RoleAware
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 76,
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 79,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 79,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 79,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 80,
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 78,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 77,
          'last-line' => 84,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRoleCallback',
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 87,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'roleCallback',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 87,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 87,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 88,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets role callback to fetch role name
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
                  'value' => 'Closure',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 86,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 86,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 85,
          'last-line' => 92,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAlwaysResolvingRole',
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 95,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'alwaysResolvingRole',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 95,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 95,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets always resolving role option
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
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 94,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 94,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 93,
          'last-line' => 100,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'CacheAdapterInterface',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 101,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 101,
              'char' => 59,
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
                  'property' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cache',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 103,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 103,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 105,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 105,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'internalCache',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 105,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 105,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 105,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 105,
                'char' => 41,
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
                      'property' => 'internalCache',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cache',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 106,
                          'char' => 45,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '_PHF_',
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 106,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 106,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 106,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 106,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 109,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 109,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 110,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cache adapter
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 102,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 102,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 102,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 101,
          'last-line' => 114,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultAccess',
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
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 115,
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
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 117,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 117,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 119,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 119,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 116,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 116,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 116,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 115,
          'last-line' => 124,
          'char' => 19,
        ),
        5 => 
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
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 125,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 125,
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
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 127,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 127,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 129,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 129,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the events manager
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 126,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 126,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 126,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 125,
          'last-line' => 134,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRoleCallback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'callback',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 135,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_callable',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'callback',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 137,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 137,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 137,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 137,
                'char' => 35,
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
                          'value' => 'Role callback must be function.',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 138,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 138,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 138,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 139,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 140,
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
                  'property' => 'roleCallback',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'callback',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 140,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 140,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 142,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 142,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets role callback to fetch role name
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
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 136,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 135,
          'last-line' => 145,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'callRoleCallback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 145,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 145,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'roleCallback',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 147,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'identity',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 147,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 149,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'roleCallback',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 149,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'roleCallback',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 149,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 149,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 149,
                  'char' => 46,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'identity',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'roleCallback',
                    'call-type' => 2,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 150,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 150,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 150,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 150,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 152,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'identity',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 152,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 152,
                'char' => 27,
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
                          'value' => 'Function defined as roleCallback must return something.',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 153,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 153,
                        'char' => 88,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 153,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 156,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'identity',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 156,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 156,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 156,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 156,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'instanceof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'identity',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 157,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'RoleAware',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 157,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 157,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 157,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 157,
                    'char' => 49,
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
                              'value' => 'Role passed as object must implement \'Phalcon\\\\Acl\\\\RoleAware\'',
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 158,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 158,
                            'char' => 99,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 158,
                        'char' => 100,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 159,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 160,
                  'char' => 15,
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
                      'property' => 'activeIdentity',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'identity',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 160,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 160,
                      'char' => 48,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'activeRole',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'identity',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 161,
                          'char' => 49,
                        ),
                        'name' => 'getRoleName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 161,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 161,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 162,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'property' => 'activeRole',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'identity',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 163,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 163,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 164,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 165,
              'char' => 5,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 145,
          'last-line' => 169,
          'char' => 22,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getAccessFromCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 171,
              'char' => 20,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'originalValues',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 172,
                'char' => 36,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 172,
              'char' => 36,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'roleCacheKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 174,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 174,
              'char' => 5,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 176,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 178,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 178,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 178,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'internalCache',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 178,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 178,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 178,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 178,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 178,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 180,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 180,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 181,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets access from cache
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
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 174,
                'char' => 15,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 170,
          'last-line' => 185,
          'char' => 22,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'exception',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Exception',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 186,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 186,
              'char' => 62,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 188,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 189,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 189,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 189,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 189,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 189,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 189,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 189,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 190,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 190,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 190,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 190,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 190,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 191,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'firewall:beforeException',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 191,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 191,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 191,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 191,
                          'char' => 66,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'exception',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 191,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 191,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 191,
                      'char' => 81,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 191,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 191,
                    'char' => 89,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 192,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 193,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 194,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 195,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles a user exception
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 186,
          'last-line' => 199,
          'char' => 22,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'fireEventOrThrowException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 201,
              'char' => 17,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 202,
              'char' => 26,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 203,
              'char' => 30,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 205,
              'char' => 5,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 207,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'roleName',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 207,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 209,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 209,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 209,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 209,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 209,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 210,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 210,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 211,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 211,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 211,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 211,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 212,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'firewall:afterCheck',
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 212,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 212,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 212,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 212,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 212,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 213,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 214,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'role',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 215,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 215,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 215,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 215,
                    'char' => 37,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'roleName',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'implode',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ', ',
                                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                                  'line' => 216,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter.zep',
                                'line' => 216,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                                  'line' => 216,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter.zep',
                                'line' => 216,
                                'char' => 47,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 216,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 216,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 217,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'roleName',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'role',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 218,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 218,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 219,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 221,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 221,
                      'char' => 25,
                    ),
                    'name' => 'throwFirewallException',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Role name ',
                                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                                    'line' => 222,
                                    'char' => 28,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'roleName',
                                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                                    'line' => 222,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                                  'line' => 222,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' doesn\'t have access to action ',
                                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                                  'line' => 222,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter.zep',
                                'line' => 222,
                                'char' => 73,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'actionName',
                                'file' => '/app/phalcon/Firewall/Adapter.zep',
                                'line' => 223,
                                'char' => 28,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 223,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' in controller ',
                              'file' => '/app/phalcon/Firewall/Adapter.zep',
                              'line' => 223,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 223,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'controllerName',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 223,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 223,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 223,
                        'char' => 62,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '403',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 225,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 225,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 225,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 226,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 227,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Fires event or throwing exception
     *',
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 200,
          'last-line' => 231,
          'char' => 22,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'saveAccessInCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 232,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 232,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'cache',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 234,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 236,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'internalCache',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 236,
                      'char' => 36,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'access',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 236,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 236,
                  'char' => 46,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 237,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 237,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 237,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 237,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 239,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'cache',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 239,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 239,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 239,
                'char' => 26,
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
                      'value' => 'cache',
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 240,
                      'char' => 19,
                    ),
                    'name' => 'set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '_PHF_',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 240,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 240,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 240,
                            'char' => 36,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'internalCache',
                            'file' => '/app/phalcon/Firewall/Adapter.zep',
                            'line' => 240,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 240,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 240,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 240,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 241,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 242,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Saves access in cache and internal cache
    *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 233,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 232,
          'last-line' => 246,
          'char' => 22,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'throwFirewallException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 247,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'exceptionCode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 247,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 247,
              'char' => 84,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'exception',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 249,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 251,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'exception',
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
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 251,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 251,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'exceptionCode',
                          'file' => '/app/phalcon/Firewall/Adapter.zep',
                          'line' => 251,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 251,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 251,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 251,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 253,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 253,
                    'char' => 17,
                  ),
                  'name' => 'handleException',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Firewall/Adapter.zep',
                        'line' => 253,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter.zep',
                      'line' => 253,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 253,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 253,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 253,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Firewall/Adapter.zep',
                    'line' => 254,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter.zep',
                  'line' => 255,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 257,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'exception',
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 257,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Firewall/Adapter.zep',
              'line' => 258,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an internal exception
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
                'file' => '/app/phalcon/Firewall/Adapter.zep',
                'line' => 248,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter.zep',
            'line' => 248,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter.zep',
          'line' => 247,
          'last-line' => 259,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Firewall/Adapter.zep',
      'line' => 25,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Firewall/Adapter.zep',
    'line' => 25,
    'char' => 14,
  ),
);