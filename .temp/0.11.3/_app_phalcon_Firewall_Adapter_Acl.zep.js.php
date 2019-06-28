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
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Firewall\\Adapter',
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 14,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'name' => 'Phalcon\\Events\\Event',
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 16,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'name' => 'Phalcon\\Firewall\\Adapter',
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 17,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'name' => 'Phalcon\\Firewall\\Exception',
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
        'name' => 'Phalcon\\Mvc\\DispatcherInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
        'line' => 19,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * FirewallZ for Phalcon\\Application which depends on acl and dispatcher
 *',
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Acl',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Adapter',
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
          'name' => 'aclServiceName',
          'docblock' => '**
     * Acl service name
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 30,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 30,
              'char' => 41,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 35,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'boundModels',
          'docblock' => '**
     * Bound models
     * @var array
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
          'name' => 'boundModelsKeyMap',
          'docblock' => '**
     * Property used for setting different key names in associated acl function than got from Binder
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 41,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 41,
              'char' => 44,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
          'name' => 'dispatcher',
          'docblock' => '**
     * Dispatcher
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
          'name' => 'multiModuleConfiguration',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 53,
            'char' => 47,
          ),
          'docblock' => '**
     * Parameter for using with multi module application
     * @var bool
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
          'name' => 'moduleSeparator',
          'default' => 
          array (
            'type' => 'string',
            'value' => ':',
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 59,
            'char' => 35,
          ),
          'docblock' => '**
     * Separator between module name and controller prefix
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 59,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 59,
              'char' => 46,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
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
          'name' => 'roleCacheCallback',
          'docblock' => '**
     * Function returning string for role cache key
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 65,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 65,
              'char' => 44,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 70,
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
              'name' => 'aclServiceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 71,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'boundModelsKeyMap',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 71,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 71,
              'char' => 86,
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
                  'property' => 'aclServiceName',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'aclServiceName',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 73,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 73,
                  'char' => 53,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'boundModelsKeyMap',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'boundModelsKeyMap',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 74,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 74,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Firewall\\Adapter\\Acl constructor
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 71,
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
          'name' => 'afterBinding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'event',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Event',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 77,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 77,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'dispatcher',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DispatcherInterface',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 77,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 77,
              'char' => 81,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 77,
              'char' => 91,
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
                  'property' => 'boundModels',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 79,
                      'char' => 44,
                    ),
                    'name' => 'getBoundModels',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 79,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 79,
                  'char' => 61,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'dispatcher',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'dispatcher',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 80,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 80,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 82,
              'char' => 14,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 82,
                  'char' => 21,
                ),
                'name' => 'handleDispatcher',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 82,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 82,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 82,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 77,
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
          'name' => 'beforeExecuteRoute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'event',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Event',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 85,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 85,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'dispatcher',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DispatcherInterface',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 85,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 85,
              'char' => 87,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 85,
              'char' => 97,
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
                  'property' => 'dispatcher',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'dispatcher',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 87,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 87,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 89,
              'char' => 14,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 89,
                  'char' => 21,
                ),
                'name' => 'handleDispatcher',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 89,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 89,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 89,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 90,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 85,
          'last-line' => 94,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDispatcher',
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
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 97,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 97,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 97,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 98,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets dispatcher
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
                  'value' => 'Dispatcher',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 96,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 96,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 95,
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
          'name' => 'isMultiModuleConfiguration',
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
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 106,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'multiModuleConfiguration',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 106,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 106,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns multiModuleConfiguration
     * @return bool
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
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 104,
          'last-line' => 111,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useMultiModuleConfiguration',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'multiModuleConfiguration',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 112,
              'char' => 78,
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
                  'property' => 'multiModuleConfiguration',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'multiModuleConfiguration',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 114,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 114,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 116,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 116,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 117,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets multiModuleConfiguration
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 112,
          'last-line' => 119,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 120,
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
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 121,
                'char' => 36,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 121,
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
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 123,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 123,
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
                  'variable' => 'explodedKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 125,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 125,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'keyWithValues',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 125,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'originalKeysJoin',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 125,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 127,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'roleCacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 127,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 127,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 127,
                'char' => 33,
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
                      'variable' => 'roleCacheKey',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '!',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 128,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 128,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 128,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 128,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 129,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 132,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'explodedKey',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '!',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 132,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 132,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 132,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 132,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 132,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 132,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 137,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'explodedKey',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 137,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 137,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 137,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 137,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 137,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 137,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 137,
                'char' => 47,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'explodedKey',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 138,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 138,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeRole',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 138,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 138,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 138,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 139,
                  'char' => 15,
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
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'join',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 139,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 139,
                            'char' => 29,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'explodedKey',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 139,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 139,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 139,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 139,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 140,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 145,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'originalValues',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 145,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 145,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 145,
                'char' => 34,
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
                      'variable' => 'originalKeysJoin',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'join',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 146,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 146,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'originalValues',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 146,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 146,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 146,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 146,
                      'char' => 59,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'keyWithValues',
                      'expr' => 
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
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 147,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 147,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 147,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'originalKeysJoin',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 147,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 147,
                          'char' => 63,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 147,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 147,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 147,
                      'char' => 77,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'access',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'parent',
                        'dynamic' => 0,
                        'name' => 'getAccessFromCache',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'keyWithValues',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 148,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 148,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 148,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 148,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 150,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'access',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 150,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 150,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 150,
                    'char' => 32,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 151,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 152,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 158,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'access',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'parent',
                        'dynamic' => 0,
                        'name' => 'getAccessFromCache',
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
                                        'type' => 'array-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'explodedKey',
                                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                          'line' => 159,
                                          'char' => 28,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '0',
                                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                          'line' => 159,
                                          'char' => 30,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 159,
                                        'char' => 32,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '!',
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 159,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 159,
                                      'char' => 36,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'explodedKey',
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 159,
                                        'char' => 49,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 159,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 159,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 159,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!*!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 159,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 159,
                                  'char' => 59,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'originalKeysJoin',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 159,
                                  'char' => 78,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 159,
                                'char' => 78,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'roleCacheKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 160,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 160,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 160,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 160,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 160,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 162,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'access',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 162,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 162,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 162,
                    'char' => 32,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'access',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 163,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 164,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 170,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'access',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'parent',
                        'dynamic' => 0,
                        'name' => 'getAccessFromCache',
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
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'explodedKey',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 171,
                                      'char' => 28,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '0',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 171,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 171,
                                    'char' => 32,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!*!*!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 171,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 171,
                                  'char' => 40,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'originalKeysJoin',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 171,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 171,
                                'char' => 59,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'roleCacheKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 172,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 172,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 172,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 172,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 172,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 174,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'access',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 174,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 174,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 174,
                    'char' => 32,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'access',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 175,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 176,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 177,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 179,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'access',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'getAccessFromCache',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 180,
                            'char' => 17,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 181,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 181,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 181,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 181,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 181,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 183,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 183,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 183,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 183,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 184,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 185,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 190,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'access',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'getAccessFromCache',
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
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'explodedKey',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 191,
                                    'char' => 24,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 191,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 191,
                                  'char' => 28,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 191,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 191,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'explodedKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 191,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 191,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 191,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 191,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!*',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 191,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 191,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 192,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 192,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 192,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 192,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 192,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 194,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 194,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 194,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 194,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'access',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 195,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 196,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 202,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'access',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'getAccessFromCache',
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
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'explodedKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 203,
                                'char' => 24,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 203,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 203,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!*!*',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 203,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 203,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 204,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 204,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 204,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 204,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 204,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 206,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 206,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 123,
                'char' => 15,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 119,
          'last-line' => 209,
          'char' => 22,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleDispatcher',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'dispatcher',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DispatcherInterface',
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 209,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 209,
              'char' => 73,
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
                  'variable' => 'acl',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'aclAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'aclRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'aclServiceName',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'boundModel',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 211,
                  'char' => 76,
                ),
                6 => 
                array (
                  'variable' => 'boundModelKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 212,
                  'char' => 26,
                ),
                7 => 
                array (
                  'variable' => 'boundModelKeyMap',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 212,
                  'char' => 44,
                ),
                8 => 
                array (
                  'variable' => 'boundModels',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 212,
                  'char' => 57,
                ),
                9 => 
                array (
                  'variable' => 'boundModelsKeyMap',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 212,
                  'char' => 76,
                ),
                10 => 
                array (
                  'variable' => 'cacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 213,
                  'char' => 21,
                ),
                11 => 
                array (
                  'variable' => 'componentName',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 213,
                  'char' => 36,
                ),
                12 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 213,
                  'char' => 47,
                ),
                13 => 
                array (
                  'variable' => 'controllerName',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 213,
                  'char' => 63,
                ),
                14 => 
                array (
                  'variable' => 'defaultAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 213,
                  'char' => 78,
                ),
                15 => 
                array (
                  'variable' => 'modelBinder',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 214,
                  'char' => 24,
                ),
                16 => 
                array (
                  'variable' => 'moduleName',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 214,
                  'char' => 36,
                ),
                17 => 
                array (
                  'variable' => 'moduleSeparator',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 214,
                  'char' => 53,
                ),
                18 => 
                array (
                  'variable' => 'originalValues',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 214,
                  'char' => 69,
                ),
                19 => 
                array (
                  'variable' => 'parameters',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 214,
                  'char' => 81,
                ),
                20 => 
                array (
                  'variable' => 'roleCacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 215,
                  'char' => 25,
                ),
                21 => 
                array (
                  'variable' => 'roleCacheCallback',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 215,
                  'char' => 44,
                ),
                22 => 
                array (
                  'variable' => 'role',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 215,
                  'char' => 50,
                ),
                23 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 215,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 217,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 217,
                      'char' => 36,
                    ),
                    'name' => 'getDI',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 217,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 217,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 218,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 218,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 218,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 218,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 218,
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
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Exception',
                          'dynamic' => 0,
                          'name' => 'containerServiceNotFound',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'the ACL service',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 220,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 220,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 221,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 221,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 221,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 222,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 224,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'defaultAccess',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 224,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultAccess',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 224,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 224,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 224,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 224,
                  'char' => 59,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 225,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 225,
                  'char' => 35,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'controllerName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_class',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dispatcher',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 226,
                            'char' => 54,
                          ),
                          'name' => 'getActiveController',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 226,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 226,
                        'char' => 76,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 226,
                    'char' => 77,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 226,
                  'char' => 77,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'boundModels',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 227,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundModels',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 227,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 227,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 227,
                  'char' => 50,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'boundModelsKeyMap',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 228,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundModelsKeyMap',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 228,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 228,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 228,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 230,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 230,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'multiModuleConfiguration',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 230,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 230,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 230,
                'char' => 44,
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
                      'variable' => 'componentName',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'ucfirst',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'dispatcher',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 232,
                                'char' => 28,
                              ),
                              'name' => 'getControllerName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 233,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 233,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 233,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 233,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 234,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'moduleSeparator',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 235,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'moduleSeparator',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 235,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 235,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 235,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'moduleName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'dispatcher',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 236,
                          'char' => 46,
                        ),
                        'name' => 'getModuleName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 236,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 236,
                      'char' => 62,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'componentName',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'moduleName',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 237,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'moduleSeparator',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 237,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 237,
                          'char' => 64,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'ucfirst',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'dispatcher',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 237,
                                  'char' => 85,
                                ),
                                'name' => 'getControllerName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 237,
                                'char' => 105,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 237,
                              'char' => 105,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 237,
                          'char' => 106,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 237,
                        'char' => 106,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 237,
                      'char' => 106,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 238,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 240,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'actionName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 240,
                      'char' => 37,
                    ),
                    'name' => 'getActionName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 240,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 240,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 242,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 242,
                      'char' => 17,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 242,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 242,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 242,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 242,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 242,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'alwaysResolvingRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 242,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 242,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 242,
                'char' => 66,
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
                      'property' => 'activeRole',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 243,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 243,
                      'char' => 44,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'activeIdentity',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 244,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 244,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 246,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 246,
                      'char' => 18,
                    ),
                    'name' => 'callRoleCallback',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 246,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 246,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 246,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 247,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 249,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'aclRole',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 249,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 249,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 249,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 249,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 252,
              'char' => 10,
            ),
            8 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 252,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeIdentity',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 252,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 252,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 252,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 252,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 252,
                'char' => 50,
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
                      'variable' => 'role',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 253,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeIdentity',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 253,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 253,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 253,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 254,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'role',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'aclRole',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 255,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 255,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 256,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 258,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'aclRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 258,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 258,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 258,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 258,
                'char' => 37,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'When using ACL service as firewall configuration you can ',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 260,
                            'char' => 75,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'pass role only as string or object implementing \'Phalcon\\\\Acl\\\\RoleAware\'.',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 262,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 262,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 262,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 262,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 263,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 265,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'cacheKey',
                  'expr' => 
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
                            'type' => 'variable',
                            'value' => 'aclRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 265,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '!',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 265,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 265,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'componentName',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 265,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 265,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '!',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 265,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 265,
                      'char' => 59,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'actionName',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 265,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 265,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 265,
                  'char' => 71,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'modelBinder',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 266,
                      'char' => 38,
                    ),
                    'name' => 'getModelBinder',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 266,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 266,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 267,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'modelBinder',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 267,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 267,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 267,
                'char' => 32,
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
                      'variable' => 'originalValues',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modelBinder',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 268,
                          'char' => 46,
                        ),
                        'name' => 'getOriginalValues',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 268,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 268,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 269,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 270,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'roleCacheCallback',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 270,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'roleCacheCallback',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 270,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 270,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 270,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 271,
              'char' => 10,
            ),
            13 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'role',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 271,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 271,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 271,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 271,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'roleCacheCallback',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 271,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 271,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 271,
                  'char' => 63,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 271,
                'char' => 63,
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
                      'variable' => 'roleCacheKey',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'roleCacheCallback',
                        'call-type' => 2,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'role',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 272,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 272,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 272,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 272,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 273,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 274,
              'char' => 11,
            ),
            14 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'aclAccess',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 274,
                      'char' => 30,
                    ),
                    'name' => 'getAccessFromCache',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 274,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 274,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'originalValues',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 274,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 274,
                        'char' => 74,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 274,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 274,
                        'char' => 88,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 274,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 274,
                  'char' => 89,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 276,
              'char' => 10,
            ),
            15 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'aclAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 276,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 276,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 276,
                'char' => 31,
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
                      'variable' => 'aclServiceName',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 277,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclServiceName',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 277,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 277,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 277,
                      'char' => 54,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'acl',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 278,
                          'char' => 44,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'aclServiceName',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 278,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 278,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 278,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 278,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 280,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'acl',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 280,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 280,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 280,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 280,
                      'char' => 38,
                    ),
                    'right' => 
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
                            'value' => 'acl',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 280,
                            'char' => 55,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Phalcon\\Acl\\AdapterInterface',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 280,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 280,
                          'char' => 86,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 280,
                        'char' => 88,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 280,
                      'char' => 88,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 280,
                    'char' => 88,
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
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'You need to add acl service to dependency injector ',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 282,
                                'char' => 73,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'container which is implementing \'Phalcon\\\\Acl\\\\AdapterInterface\'',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 284,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 284,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 284,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 284,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 285,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 288,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'acl',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 288,
                        'char' => 21,
                      ),
                      'name' => 'isRole',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'aclRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 288,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 288,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 288,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 288,
                    'char' => 38,
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
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'Role ',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 289,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'aclRole',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 289,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 289,
                                'char' => 53,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' doesn\'t exist in ACL',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 289,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 289,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 289,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 289,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 290,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 293,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'acl',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 293,
                        'char' => 21,
                      ),
                      'name' => 'isComponent',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'componentName',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 293,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 293,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 293,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 293,
                    'char' => 49,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 294,
                              'char' => 34,
                            ),
                            'name' => 'fireEventOrThrowException',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'aclRole',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 295,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 295,
                                'char' => 28,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 296,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 296,
                                'char' => 31,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 297,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 297,
                                'char' => 35,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 299,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 299,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 299,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 299,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 301,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 301,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 301,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 301,
                        'char' => 41,
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 302,
                              'char' => 26,
                            ),
                            'name' => 'saveAccessInCache',
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
                                      'type' => 'variable',
                                      'value' => 'cacheKey',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 303,
                                      'char' => 34,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '!',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 303,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 303,
                                    'char' => 38,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'roleCacheKey',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 303,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 303,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 303,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 305,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 305,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 305,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 306,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 307,
                              'char' => 26,
                            ),
                            'name' => 'saveAccessInCache',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'cacheKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 307,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 307,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 307,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 307,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 307,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 308,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 310,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 310,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 310,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 310,
                        'char' => 36,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 311,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 312,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 313,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 315,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'boundModels',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 315,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 315,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 315,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'boundModels',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 316,
                        'char' => 62,
                      ),
                      'key' => 'boundModelKey',
                      'value' => 'boundModel',
                      'reverse' => 0,
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'boundModelKeyMap',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 317,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'boundModelsKeyMap',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 317,
                                'char' => 65,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'boundModelKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 317,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 317,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 317,
                            'char' => 81,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'parameters',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'boundModelKeyMap',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 318,
                                      'char' => 56,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'boundModel',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 318,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 318,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 319,
                              'char' => 21,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'parameters',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'boundModelKey',
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 320,
                                      'char' => 53,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'boundModel',
                                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                    'line' => 320,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 320,
                                  'char' => 67,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 321,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 322,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 323,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 325,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 325,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 325,
                    'char' => 33,
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
                          'variable' => 'aclAccess',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'acl',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 326,
                              'char' => 37,
                            ),
                            'name' => 'isAllowed',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 326,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 326,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'componentName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 326,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 326,
                                'char' => 67,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 326,
                                  'char' => 79,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 326,
                                'char' => 79,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 326,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 326,
                          'char' => 80,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 327,
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
                          'variable' => 'aclAccess',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'acl',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 328,
                              'char' => 37,
                            ),
                            'name' => 'isAllowed',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 328,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 328,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'componentName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 328,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 328,
                                'char' => 67,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 328,
                                  'char' => 79,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 328,
                                'char' => 79,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 328,
                                  'char' => 91,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 328,
                                'char' => 91,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 328,
                            'char' => 92,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 328,
                          'char' => 92,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 329,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 331,
                  'char' => 15,
                ),
                6 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'cacheKey',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'acl',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 331,
                          'char' => 32,
                        ),
                        'name' => 'getActiveKey',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 331,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 331,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 333,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'acl',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 333,
                        'char' => 20,
                      ),
                      'name' => 'getActiveFunction',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 333,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 333,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 333,
                    'char' => 49,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'empty',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 334,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 334,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 334,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'greater',
                          'left' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'acl',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 334,
                              'char' => 45,
                            ),
                            'name' => 'getActiveFunctionCustomArgumentsCount',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 334,
                            'char' => 86,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 334,
                            'char' => 90,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 334,
                          'char' => 90,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 334,
                        'char' => 90,
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
                              'operator' => 'concat-assign',
                              'variable' => 'cacheKey',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 335,
                                  'char' => 38,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'join',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '!',
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 335,
                                        'char' => 46,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 335,
                                      'char' => 46,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'originalValues',
                                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                        'line' => 335,
                                        'char' => 62,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                      'line' => 335,
                                      'char' => 62,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 335,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 335,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 335,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 336,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 337,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 337,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 337,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 337,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'role',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 337,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 337,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 337,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 337,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 337,
                        'char' => 66,
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
                              'operator' => 'concat-assign',
                              'variable' => 'cacheKey',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 338,
                                  'char' => 38,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'roleCacheKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                  'line' => 338,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                                'line' => 338,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 338,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 339,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 340,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 342,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 342,
                      'char' => 18,
                    ),
                    'name' => 'saveAccessInCache',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 342,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 342,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclAccess',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 342,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 342,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 342,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 343,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 345,
              'char' => 11,
            ),
            16 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 345,
                      'char' => 26,
                    ),
                    'name' => 'fireEventOrThrowException',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclRole',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 345,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 345,
                        'char' => 60,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'actionName',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 345,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 345,
                        'char' => 72,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'controllerName',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 345,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 345,
                        'char' => 88,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclAccess',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 345,
                          'char' => 99,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 345,
                        'char' => 99,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 345,
                    'char' => 100,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 345,
                  'char' => 100,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 347,
              'char' => 10,
            ),
            17 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 347,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 347,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 347,
                'char' => 28,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 348,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 349,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 350,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 209,
          'last-line' => 352,
          'char' => 22,
        ),
        8 => 
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
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 352,
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
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 352,
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
                  'variable' => 'explodedKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 354,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'activeRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 354,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 356,
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
                  'variable' => 'explodedKey',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '!',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 356,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 356,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 356,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 356,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 356,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 356,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'activeRole',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 357,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 357,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 357,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 357,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 362,
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
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'explodedKey',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 362,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 362,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 362,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 362,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 362,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'explodedKey',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                          'line' => 363,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'activeRole',
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 363,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 363,
                      'char' => 44,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'join',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 364,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 364,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'explodedKey',
                              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                              'line' => 364,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                            'line' => 364,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                        'line' => 364,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 364,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 367,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'saveAccessInCache',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 367,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 367,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'access',
                      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                      'line' => 367,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                    'line' => 367,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
                'line' => 367,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
              'line' => 368,
              'char' => 5,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
            'line' => 353,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
          'line' => 352,
          'last-line' => 369,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Acl.zep',
    'line' => 24,
    'char' => 5,
  ),
);