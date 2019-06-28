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
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Firewall',
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\DispatcherInterface',
        'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'alias' => 'CacheAdapterInterface',
        'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
        'line' => 14,
        'char' => 68,
      ),
    ),
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Mvc\\Dispatcher\\Firewall adapters
 *',
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'getDefaultAccess',
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
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 24,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 24,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
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
          'name' => 'getRoleCallback',
          'docblock' => '**
     * Gets role callback to fetch role name
     *',
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 29,
          'last-line' => 33,
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
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 34,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 34,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAlwaysResolvingRole',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'alwaysResolvingRole',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
              'line' => 39,
              'char' => 68,
            ),
          ),
          'docblock' => '**
     * Sets always resolving role option
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 39,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 39,
          'last-line' => 43,
          'char' => 19,
        ),
        4 => 
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
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 44,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
              'line' => 44,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Sets cache backend
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
                  'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                  'line' => 44,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 44,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 44,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
              'line' => 49,
              'char' => 55,
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
                  'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                  'line' => 49,
                  'char' => 78,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 49,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 49,
            'char' => 78,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 49,
          'last-line' => 53,
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
              'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
              'line' => 54,
              'char' => 49,
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
                  'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                  'line' => 54,
                  'char' => 72,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
                'line' => 54,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
            'line' => 54,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
          'line' => 54,
          'last-line' => 55,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
      'line' => 55,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Firewall/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);