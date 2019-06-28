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
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Firewall\\Adapter\\Micro',
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 14,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\Events\\Event',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 16,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 17,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\Firewall\\Adapter',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 18,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\Firewall\\Exception',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 19,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
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
        'name' => 'Phalcon\\Mvc\\Micro',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 20,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\BinderInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 21,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 22,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Router',
        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
        'line' => 22,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 26,
    'char' => 2,
  ),
  12 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Firewall for Phalcon\\Mvc\\Micro which depends on ACL
 *',
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 27,
    'char' => 5,
  ),
  13 => 
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 33,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 33,
              'char' => 41,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 38,
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
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 44,
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
     * Property used for setting different key names in associated ACL function
     * than got from Binder
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 45,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 45,
              'char' => 44,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 50,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'componentName',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Micro',
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 51,
            'char' => 37,
          ),
          'docblock' => '**
     * Component name used to acquire access, be default it\'s Micro
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 51,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 51,
              'char' => 48,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 56,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'micro',
          'docblock' => '**
     * Micro object
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 62,
          'char' => 6,
        ),
        5 => 
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 63,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 63,
              'char' => 44,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 68,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'router',
          'docblock' => '**
     * Router object
     * @var mixed
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 75,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'routeNameConfiguration',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 76,
            'char' => 45,
          ),
          'docblock' => '**
     * By default using route names which are required, you can change it to
     * false to use route patterns
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 76,
              'char' => 51,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 78,
          'char' => 10,
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 78,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'boundModelsKeyMap',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 78,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 78,
              'char' => 88,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 80,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 80,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 81,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 81,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 82,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 78,
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 84,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 84,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'micro',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Micro',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 84,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 84,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 84,
              'char' => 72,
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
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 86,
                      'char' => 39,
                    ),
                    'name' => 'getBoundModels',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 86,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 86,
                  'char' => 56,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'router',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 87,
                      'char' => 39,
                    ),
                    'name' => 'getRouter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 87,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 87,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'micro',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'micro',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 88,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 88,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 90,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 90,
                  'char' => 21,
                ),
                'name' => 'handleRouter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 90,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 90,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 90,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 91,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 84,
          'last-line' => 93,
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 93,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 93,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'micro',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Micro',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 93,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 93,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 93,
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
                  'property' => 'router',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 95,
                      'char' => 34,
                    ),
                    'name' => 'getRouter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 95,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 95,
                  'char' => 46,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'micro',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'micro',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 96,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 96,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 98,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 98,
                  'char' => 21,
                ),
                'name' => 'handleRouter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 98,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 98,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 98,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 93,
          'last-line' => 103,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMicro',
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 106,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'micro',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 106,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 106,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets micro
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
                  'value' => 'Micro',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 105,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 104,
          'last-line' => 111,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isRouteNameConfiguration',
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 114,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routeNameConfiguration',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 114,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 114,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 115,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets route name configuration
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 113,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 113,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 112,
          'last-line' => 119,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 121,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 122,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 123,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 125,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 127,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'roleName',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 127,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 129,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 129,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 130,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 130,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 130,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 130,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 131,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 131,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 131,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 131,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 131,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 131,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 132,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 133,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 134,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 134,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 134,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 134,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 135,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 135,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 135,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 135,
                                'char' => 47,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 135,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 135,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 136,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 137,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 137,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 138,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 140,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 140,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routeNameConfiguration',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 140,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 140,
                    'char' => 45,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 141,
                          'char' => 29,
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
                                    'type' => 'string',
                                    'value' => 'Role name ',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 142,
                                    'char' => 32,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'roleName',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 142,
                                    'char' => 43,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 142,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' doesn\'t have access to route called ',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 142,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 142,
                                'char' => 83,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'actionName',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 142,
                                'char' => 95,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 142,
                              'char' => 95,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 142,
                            'char' => 95,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '403',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 144,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 144,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 144,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 145,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 146,
                          'char' => 29,
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
                                    'type' => 'string',
                                    'value' => 'Role name ',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 147,
                                    'char' => 32,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'roleName',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 147,
                                    'char' => 43,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 147,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' doesn\'t have access to route with pattern ',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 147,
                                  'char' => 89,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 147,
                                'char' => 89,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'actionName',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 147,
                                'char' => 101,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 147,
                              'char' => 101,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 147,
                            'char' => 101,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '403',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 149,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 149,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 149,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 150,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 151,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Fires event or throwing exception
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 120,
          'last-line' => 154,
          'char' => 22,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 155,
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 156,
                'char' => 36,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 156,
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 158,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 158,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 160,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 160,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'keyWithValues',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 160,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'originalKeysJoin',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 160,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 162,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 162,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 162,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 162,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 163,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 163,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 163,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 163,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 164,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 166,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 166,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 166,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 166,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 166,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 166,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 166,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 171,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 171,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 171,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 171,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 171,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 171,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 171,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 171,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 172,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 172,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeRole',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 172,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 172,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 172,
                      'char' => 50,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 173,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 173,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'explodedKey',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 173,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 173,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 173,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 173,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 174,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 179,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 179,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 179,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 179,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 180,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 180,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'originalValues',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 180,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 180,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 180,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 180,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 181,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 181,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 181,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'originalKeysJoin',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 181,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 181,
                          'char' => 63,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 181,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 181,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 181,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 182,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 182,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 182,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 182,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 184,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 184,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 184,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 184,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 185,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 186,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 188,
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
                                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                          'line' => 189,
                                          'char' => 28,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '0',
                                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                          'line' => 189,
                                          'char' => 30,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 189,
                                        'char' => 32,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '!',
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 189,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 189,
                                      'char' => 36,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'explodedKey',
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 189,
                                        'char' => 49,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 189,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 189,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 189,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!*!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 189,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 189,
                                  'char' => 59,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'originalKeysJoin',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 189,
                                  'char' => 78,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 189,
                                'char' => 78,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'roleCacheKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 190,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 190,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 190,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 190,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 190,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 192,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 192,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 192,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 192,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 193,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 194,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 196,
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
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 197,
                                      'char' => 28,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '0',
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 197,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 197,
                                    'char' => 32,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!*!*!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 197,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 197,
                                  'char' => 40,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'originalKeysJoin',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 197,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 197,
                                'char' => 59,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'roleCacheKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 198,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 198,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 198,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 198,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 198,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 200,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 200,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 200,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 200,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 201,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 202,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 203,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 205,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 206,
                            'char' => 17,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 207,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 207,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 207,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 207,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 207,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 209,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 209,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 209,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 209,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 210,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 211,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 217,
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
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 218,
                                    'char' => 24,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 218,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 218,
                                  'char' => 28,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 218,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 218,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'explodedKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 218,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 218,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 218,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 218,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!*',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 218,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 218,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 219,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 219,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 219,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 219,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 219,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 221,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 221,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 221,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 221,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 222,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 223,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 229,
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
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 230,
                                'char' => 24,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 230,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 230,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!*!*',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 230,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 230,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'roleCacheKey',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 231,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 231,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 231,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 231,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 231,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 233,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 233,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 234,
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
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 158,
                'char' => 15,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 159,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 154,
          'last-line' => 236,
          'char' => 22,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleRouter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'micro',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Micro',
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 236,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 236,
              'char' => 50,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'aclAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'aclRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'aclServiceName',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'boundModel',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 238,
                  'char' => 76,
                ),
                6 => 
                array (
                  'variable' => 'boundModelKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 239,
                  'char' => 26,
                ),
                7 => 
                array (
                  'variable' => 'boundModelKeyMap',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 239,
                  'char' => 44,
                ),
                8 => 
                array (
                  'variable' => 'boundModels',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 239,
                  'char' => 57,
                ),
                9 => 
                array (
                  'variable' => 'boundModelsKeyMap',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 239,
                  'char' => 76,
                ),
                10 => 
                array (
                  'variable' => 'cacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 240,
                  'char' => 21,
                ),
                11 => 
                array (
                  'variable' => 'componentName',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 240,
                  'char' => 36,
                ),
                12 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 240,
                  'char' => 47,
                ),
                13 => 
                array (
                  'variable' => 'defaultAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 240,
                  'char' => 62,
                ),
                14 => 
                array (
                  'variable' => 'modelBinder',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 240,
                  'char' => 75,
                ),
                15 => 
                array (
                  'variable' => 'originalValues',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 241,
                  'char' => 27,
                ),
                16 => 
                array (
                  'variable' => 'parameters',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 241,
                  'char' => 39,
                ),
                17 => 
                array (
                  'variable' => 'role',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 241,
                  'char' => 45,
                ),
                18 => 
                array (
                  'variable' => 'roleCacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 241,
                  'char' => 59,
                ),
                19 => 
                array (
                  'variable' => 'roleCacheCallback',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 241,
                  'char' => 78,
                ),
                20 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 242,
                  'char' => 18,
                ),
                21 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 242,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 244,
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
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 244,
                      'char' => 31,
                    ),
                    'name' => 'getDI',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 244,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 244,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 245,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 245,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 245,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 245,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 245,
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
                          'value' => 'A dependency injector container is required to obtain ACL service',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 248,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 248,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 248,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 251,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 251,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultAccess',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 251,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 251,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 251,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 251,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 252,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 252,
                  'char' => 35,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'route',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 253,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'router',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 253,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 253,
                      'char' => 46,
                    ),
                    'name' => 'getMatchedRoute',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 253,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 253,
                  'char' => 64,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 254,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundModels',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 254,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 254,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 254,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 255,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundModelsKeyMap',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 255,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 255,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 255,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 257,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 257,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routeNameConfiguration',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 257,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 257,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'actionName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 258,
                          'char' => 36,
                        ),
                        'name' => 'getName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 258,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 258,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 259,
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
                      'variable' => 'actionName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 260,
                          'char' => 36,
                        ),
                        'name' => 'getPattern',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 260,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 260,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 263,
              'char' => 10,
            ),
            5 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 263,
                      'char' => 17,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 263,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 263,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 263,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 263,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 263,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'alwaysResolvingRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 263,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 263,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 263,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 264,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 264,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 265,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 265,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 267,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 267,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 267,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 267,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 267,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 268,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 270,
              'char' => 11,
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
                  'variable' => 'aclRole',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 270,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 270,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 270,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 270,
                  'char' => 45,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'componentName',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 271,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'componentName',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 271,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 271,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 271,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 273,
              'char' => 10,
            ),
            7 => 
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 273,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 273,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 273,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 273,
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
                          'type' => 'string',
                          'value' => 'When using ACL service as firewall configuration you can pass role only as string or object implementing \'Phalcon\\\\Acl\\\\RoleAware\'.',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 276,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 276,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 276,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 277,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 280,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 280,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeIdentity',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 280,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 280,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 280,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 280,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 280,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 281,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeIdentity',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 281,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 281,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 281,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 282,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 283,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 283,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 284,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 286,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 286,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '!',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 286,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 286,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'componentName',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 286,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 286,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '!',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 286,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 286,
                      'char' => 59,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'actionName',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 286,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 286,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 286,
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
                      'value' => 'micro',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 287,
                      'char' => 33,
                    ),
                    'name' => 'getModelBinder',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 287,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 287,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 289,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'modelBinder',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 289,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 289,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 289,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 290,
                          'char' => 46,
                        ),
                        'name' => 'getOriginalValues',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 290,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 290,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 291,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 293,
              'char' => 11,
            ),
            11 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 293,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'roleCacheCallback',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 293,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 293,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 293,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 295,
              'char' => 10,
            ),
            12 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 295,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 295,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 295,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 295,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'roleCacheCallback',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 295,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 295,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 295,
                  'char' => 63,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 295,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 296,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 296,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 296,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 296,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 297,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 299,
              'char' => 11,
            ),
            13 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 299,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 299,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 299,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'originalValues',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 299,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 299,
                        'char' => 74,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'roleCacheKey',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 299,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 299,
                        'char' => 88,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 299,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 299,
                  'char' => 89,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 301,
              'char' => 10,
            ),
            14 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'aclAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 301,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 301,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 301,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 302,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclServiceName',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 302,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 302,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 302,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 303,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 303,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 303,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 303,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 303,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 305,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 305,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 305,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 305,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 305,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 305,
                            'char' => 55,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Phalcon\\Acl\\AdapterInterface',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 305,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 305,
                          'char' => 86,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 305,
                        'char' => 88,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 305,
                      'char' => 88,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 305,
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
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 307,
                                'char' => 73,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'container which is implementing \'Phalcon\\\\Acl\\\\AdapterInterface\'',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 309,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 309,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 309,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 309,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 310,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 313,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 313,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 313,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 313,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 313,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 313,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 315,
                                  'char' => 27,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'aclRole',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 315,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 315,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' doesn\'t exist in ACL',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 316,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 316,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 316,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 316,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 317,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 320,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 320,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 320,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 320,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 320,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 320,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 321,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 322,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 322,
                                'char' => 28,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 323,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 323,
                                'char' => 31,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'componentName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 324,
                                  'char' => 34,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 324,
                                'char' => 34,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 326,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 326,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 326,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 326,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 328,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 328,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 328,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 328,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 329,
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
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 330,
                                      'char' => 34,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '!',
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 330,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 330,
                                    'char' => 38,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'roleCacheKey',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 330,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 330,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 330,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 332,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 332,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 332,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 333,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 334,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 334,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 334,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAccess',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 334,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 334,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 334,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 335,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 337,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 337,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 337,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 337,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 338,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 339,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 340,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 342,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 342,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 342,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 342,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 343,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 344,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'boundModelsKeyMap',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 344,
                                'char' => 65,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'boundModelKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 344,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 344,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 344,
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
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 345,
                                      'char' => 56,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'boundModel',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 345,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 345,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 346,
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
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 347,
                                      'char' => 53,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'boundModel',
                                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                    'line' => 347,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 347,
                                  'char' => 67,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 348,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 349,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 350,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 352,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 352,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 352,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 353,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 353,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 353,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'componentName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 353,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 353,
                                'char' => 67,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 353,
                                  'char' => 79,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 353,
                                'char' => 79,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 353,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 353,
                          'char' => 80,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 354,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 355,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 355,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 355,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'componentName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 355,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 355,
                                'char' => 67,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 355,
                                  'char' => 79,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 355,
                                'char' => 79,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 355,
                                  'char' => 91,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 355,
                                'char' => 91,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 355,
                            'char' => 92,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 355,
                          'char' => 92,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 356,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 358,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 358,
                          'char' => 32,
                        ),
                        'name' => 'getActiveKey',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 358,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 358,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 360,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 360,
                        'char' => 20,
                      ),
                      'name' => 'getActiveFunction',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 360,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 360,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 360,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 361,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 361,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 361,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 361,
                              'char' => 45,
                            ),
                            'name' => 'getActiveFunctionCustomArgumentsCount',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 361,
                            'char' => 86,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 361,
                            'char' => 90,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 361,
                          'char' => 90,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 361,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 362,
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
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 362,
                                        'char' => 46,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 362,
                                      'char' => 46,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'originalValues',
                                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                        'line' => 362,
                                        'char' => 62,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                      'line' => 362,
                                      'char' => 62,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 362,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 362,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 362,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 363,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 365,
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
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 365,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 365,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 365,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 365,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 365,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 365,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 365,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 365,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 366,
                                  'char' => 38,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'roleCacheKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                  'line' => 366,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                                'line' => 366,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 366,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 367,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 368,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 370,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 370,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 370,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 370,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclAccess',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 370,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 370,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 370,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 371,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 373,
              'char' => 11,
            ),
            15 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 373,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 374,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 374,
                        'char' => 20,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'actionName',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 375,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 375,
                        'char' => 23,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'componentName',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 376,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 376,
                        'char' => 26,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'aclAccess',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 378,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 378,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 378,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 378,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 380,
              'char' => 10,
            ),
            16 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 380,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 380,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 380,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 381,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 382,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 383,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 236,
          'last-line' => 385,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 385,
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
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 385,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 387,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'activeRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 387,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 389,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 389,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 389,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 389,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 389,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 389,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 389,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 390,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 390,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 390,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 390,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 396,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 396,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 396,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 396,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 396,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 396,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                          'line' => 397,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'activeRole',
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 397,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 397,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 398,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 398,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'explodedKey',
                              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                              'line' => 398,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                            'line' => 398,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                        'line' => 398,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 398,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                  'line' => 399,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 401,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 401,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 401,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'access',
                      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                      'line' => 401,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                    'line' => 401,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
                'line' => 401,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
              'line' => 402,
              'char' => 5,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
            'line' => 386,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
          'line' => 385,
          'last-line' => 403,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
      'line' => 27,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Micro/Acl.zep',
    'line' => 27,
    'char' => 5,
  ),
);