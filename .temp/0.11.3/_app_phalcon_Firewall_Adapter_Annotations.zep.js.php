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
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Firewall\\Adapter',
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Annotations\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 13,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Events\\Event',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Firewall\\Adapter',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 16,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Firewall\\Exception',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 17,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\DispatcherInterface',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 18,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
        'name' => 'ReflectionClass',
        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
        'line' => 19,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Firewall which depends on annotations and dispatcher
 *',
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Annotations',
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
          'name' => 'activeArgumentsNumber',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
            'line' => 30,
            'char' => 40,
          ),
          'docblock' => '**
     * Number of active active arguments in active annotation
     * @var int
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
          'name' => 'annotationsAdapter',
          'docblock' => '**
     * Adapter for annotations
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 36,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 36,
              'char' => 45,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 41,
          'char' => 6,
        ),
        2 => 
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
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
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
          'name' => 'resolvedRole',
          'docblock' => '**
     * Role for which access was granted
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 51,
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
              'name' => 'annotationsAdapter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 52,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 52,
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
                  'property' => 'annotationsAdapter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'annotationsAdapter',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 54,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 54,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Firewall\\Adapter\\Annotations constructor
     *',
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 52,
          'last-line' => 57,
          'char' => 19,
        ),
        1 => 
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
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 57,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 57,
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
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 57,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 57,
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
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 57,
              'char' => 97,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 59,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 59,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'cacheKey',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 59,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 59,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'controllerClass',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 59,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'controllerName',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 60,
                  'char' => 27,
                ),
                6 => 
                array (
                  'variable' => 'defaultAccess',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 60,
                  'char' => 42,
                ),
                7 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 60,
                  'char' => 57,
                ),
                8 => 
                array (
                  'variable' => 'role',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 60,
                  'char' => 63,
                ),
                9 => 
                array (
                  'variable' => 'singleRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 60,
                  'char' => 75,
                ),
                10 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 61,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 63,
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
                  'property' => 'activeArgumentsNumber',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 63,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 63,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 65,
              'char' => 11,
            ),
            2 => 
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 65,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 65,
                  'char' => 44,
                ),
                1 => 
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
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 66,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultAccess',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 66,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 66,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 66,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 66,
                  'char' => 60,
                ),
                2 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 67,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 67,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 67,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 67,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 67,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 67,
                  'char' => 72,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'controllerName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 68,
                      'char' => 45,
                    ),
                    'name' => 'getControllerName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 68,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 68,
                  'char' => 65,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'controllerClass',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 69,
                      'char' => 45,
                    ),
                    'name' => 'getControllerClass',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 69,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 69,
                  'char' => 66,
                ),
                5 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 70,
                      'char' => 45,
                    ),
                    'name' => 'getActionName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 70,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 70,
                  'char' => 61,
                ),
                6 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'resolvedRole',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 71,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 71,
                  'char' => 38,
                ),
                7 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 72,
                      'char' => 45,
                    ),
                    'name' => 'getDI',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 72,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 72,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 74,
              'char' => 10,
            ),
            3 => 
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 74,
                      'char' => 17,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 74,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 74,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 74,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 74,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 74,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'alwaysResolvingRole',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 74,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 74,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 74,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 75,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 75,
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
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 76,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 76,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 78,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 78,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 78,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 78,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 78,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 81,
              'char' => 11,
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
                  'variable' => 'role',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 81,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRole',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 81,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 81,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 81,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 82,
              'char' => 10,
            ),
            5 => 
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 82,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 82,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 82,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 82,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'role',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 83,
                    'char' => 36,
                  ),
                  'value' => 'singleRole',
                  'reverse' => 0,
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
                                    'value' => 'singleRole',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 84,
                                    'char' => 43,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 84,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 84,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 84,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 84,
                                'char' => 64,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '!',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 84,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 84,
                              'char' => 68,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'actionName',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 84,
                              'char' => 80,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 84,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 84,
                          'char' => 80,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'access',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 85,
                              'char' => 37,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 85,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 85,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 85,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 85,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 87,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'access',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 87,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 87,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'boolean',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 87,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 87,
                        'char' => 45,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 89,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 90,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 91,
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
                                'value' => 'role',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 92,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '!',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 92,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 92,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'controllerName',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 92,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 92,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '!',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 92,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 92,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'actionName',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 92,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 92,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 92,
                      'char' => 70,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'access',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 93,
                          'char' => 33,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 93,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 93,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 93,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 93,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 96,
              'char' => 10,
            ),
            6 => 
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
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'role',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 96,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 96,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 96,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 96,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'role',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 96,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 96,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 96,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 96,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 96,
                'char' => 58,
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
                            'value' => 'When using firewall based on annotations you must pass ',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 98,
                            'char' => 73,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'role as string, array or object implementing \'RoleAware\'.',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 100,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 100,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 100,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 100,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 101,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 103,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 103,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'annotationsAdapter',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 103,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 103,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 103,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 103,
                'char' => 45,
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
                            'value' => 'You need to set annotations adapter for firewall based ',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 105,
                            'char' => 73,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'on annotations configurator to work',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 107,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 107,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 107,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 107,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 108,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 110,
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
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 110,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 110,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 110,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 110,
                'char' => 43,
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
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 111,
                      'char' => 27,
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
                          'value' => 'firewall:beforeCheck',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 111,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 111,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 111,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 111,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 111,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 112,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 114,
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
                    'value' => 'access',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 114,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 114,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 114,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 114,
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
                      'variable' => 'access',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 115,
                          'char' => 31,
                        ),
                        'name' => 'checkControllerAnnotationAccess',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'controllerClass',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 116,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 116,
                            'char' => 32,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'controllerName',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 117,
                              'char' => 31,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 117,
                            'char' => 31,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'role',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 119,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 119,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 119,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 119,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 121,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'access',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 121,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 121,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'boolean',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 121,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 121,
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
                          'variable' => 'access',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 122,
                              'char' => 35,
                            ),
                            'name' => 'checkActionAnnotationAccess',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerClass',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 123,
                                  'char' => 36,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 123,
                                'char' => 36,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 124,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 124,
                                'char' => 35,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 125,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 125,
                                'char' => 31,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 127,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 127,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 127,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 127,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 128,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 130,
                  'char' => 14,
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
                        'value' => 'access',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 130,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 130,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'boolean',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 130,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 130,
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
                          'variable' => 'access',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultAccess',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 131,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 131,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 133,
                      'char' => 18,
                    ),
                    1 => 
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
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 133,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 133,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 133,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 133,
                        'char' => 41,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'role',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 134,
                            'char' => 44,
                          ),
                          'value' => 'singleRole',
                          'reverse' => 0,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 135,
                                  'char' => 30,
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'singleRole',
                                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                              'line' => 136,
                                              'char' => 40,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '!',
                                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                              'line' => 136,
                                              'char' => 44,
                                            ),
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 136,
                                            'char' => 44,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'controllerName',
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 136,
                                            'char' => 61,
                                          ),
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 136,
                                          'char' => 61,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '!',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 136,
                                          'char' => 65,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 136,
                                        'char' => 65,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'actionName',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 136,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 136,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 136,
                                    'char' => 77,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'access',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 138,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 138,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 138,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 139,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 140,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 141,
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'role',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 142,
                                          'char' => 30,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '!',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 142,
                                          'char' => 34,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 142,
                                        'char' => 34,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'controllerName',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 142,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 142,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '!',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 142,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 142,
                                    'char' => 55,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'actionName',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 142,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 142,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 142,
                                'char' => 67,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'access',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 144,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 144,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 144,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 145,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 146,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 149,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 149,
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
                          'value' => 'role',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 150,
                          'char' => 17,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 150,
                        'char' => 17,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'actionName',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 151,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 151,
                        'char' => 23,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'controllerName',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 152,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 152,
                        'char' => 27,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'access',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 154,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 154,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 154,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 154,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 156,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 156,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 156,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 156,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 157,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 158,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 57,
          'last-line' => 163,
          'char' => 19,
        ),
        2 => 
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
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 166,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 166,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 166,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 167,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 165,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 164,
          'last-line' => 169,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkControllerAnnotationAccess',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerClass',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 169,
              'char' => 78,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 169,
              'char' => 101,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 169,
              'char' => 111,
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
                  'variable' => 'annotationsAdapter',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 171,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'reflector',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 171,
                  'char' => 42,
                ),
                2 => 
                array (
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 171,
                  'char' => 55,
                ),
                3 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 171,
                  'char' => 63,
                ),
                4 => 
                array (
                  'variable' => 'singleRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 171,
                  'char' => 75,
                ),
                5 => 
                array (
                  'variable' => 'resolvedRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 172,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 174,
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
                  'variable' => 'annotationsAdapter',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 174,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotationsAdapter',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 174,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 174,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 174,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'reflector',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotationsAdapter',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 175,
                      'char' => 53,
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
                          'value' => 'controllerClass',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 175,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 175,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 175,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 175,
                  'char' => 74,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflector',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 176,
                      'char' => 44,
                    ),
                    'name' => 'getClassAnnotations',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 176,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 176,
                  'char' => 66,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'access',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 177,
                      'char' => 39,
                    ),
                    'name' => 'checkAnnotations',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 177,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 177,
                        'char' => 68,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'role',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 177,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 177,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 177,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 177,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 179,
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
                    'value' => 'access',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 179,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 179,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 179,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 179,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 180,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'activeArgumentsNumber',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 180,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 180,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 180,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 180,
                    'char' => 48,
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
                          'variable' => 'resolvedRole',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 181,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'resolvedRole',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 181,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 181,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 181,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 183,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'resolvedRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 183,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 183,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 183,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 183,
                        'char' => 49,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'resolvedRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 184,
                            'char' => 52,
                          ),
                          'value' => 'singleRole',
                          'reverse' => 0,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 185,
                                  'char' => 30,
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'singleRole',
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 186,
                                            'char' => 40,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '!',
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 186,
                                            'char' => 44,
                                          ),
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 186,
                                          'char' => 44,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'controllerName',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 186,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 186,
                                        'char' => 61,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '!*',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 186,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 186,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 186,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'access',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 188,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 188,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 188,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 189,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 190,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 191,
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'resolvedRole',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 192,
                                        'char' => 38,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '!',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 192,
                                        'char' => 42,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 192,
                                      'char' => 42,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'controllerName',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 192,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 192,
                                    'char' => 59,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '!*',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 192,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 192,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 192,
                                'char' => 63,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'access',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 194,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 194,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 194,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 195,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 196,
                      'char' => 13,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 197,
                          'char' => 22,
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
                                  'type' => 'string',
                                  'value' => '*!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 198,
                                  'char' => 24,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerName',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 198,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 198,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '!*',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 198,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 198,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 198,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'access',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 200,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 200,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 200,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 201,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 202,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 204,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 204,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 205,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 169,
          'last-line' => 207,
          'char' => 22,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkAnnotations',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'annotations',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 207,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 207,
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
                  'variable' => 'returnAllow',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 209,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 211,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'annotations',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 211,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 211,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 211,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 212,
                      'char' => 28,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Allow',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 212,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 212,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 212,
                    'char' => 40,
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
                          'variable' => 'returnAllow',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 213,
                              'char' => 40,
                            ),
                            'name' => 'handleAnnotation',
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
                                    'value' => 'annotations',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 214,
                                    'char' => 33,
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
                                        'value' => 'Allow',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 214,
                                        'char' => 43,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 214,
                                      'char' => 43,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 214,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 214,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 215,
                                  'char' => 25,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 215,
                                'char' => 25,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 217,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 217,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 217,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 217,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 219,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'returnAllow',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 219,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 219,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'boolean',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 219,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 219,
                        'char' => 50,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'returnAllow',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 220,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 221,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 222,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 224,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 224,
                      'char' => 28,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Deny',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 224,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 224,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 224,
                    'char' => 39,
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
                          'variable' => 'returnAllow',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 225,
                              'char' => 40,
                            ),
                            'name' => 'handleAnnotation',
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
                                    'value' => 'annotations',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 226,
                                    'char' => 33,
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
                                        'value' => 'Deny',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 226,
                                        'char' => 42,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 226,
                                      'char' => 42,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 226,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 226,
                                'char' => 43,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'false',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 227,
                                  'char' => 26,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 227,
                                'char' => 26,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 229,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 229,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 229,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 229,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 231,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'returnAllow',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 231,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 231,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'boolean',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 231,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 231,
                        'char' => 50,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'returnAllow',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 232,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 233,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 234,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 235,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 237,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 237,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 238,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 207,
          'last-line' => 240,
          'char' => 22,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkActionAnnotationAccess',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerClass',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 241,
              'char' => 31,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 242,
              'char' => 30,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 243,
              'char' => 26,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 245,
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
                  'variable' => 'annotationsAdapter',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 247,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 247,
                  'char' => 44,
                ),
                2 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 247,
                  'char' => 52,
                ),
                3 => 
                array (
                  'variable' => 'singleRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 247,
                  'char' => 64,
                ),
                4 => 
                array (
                  'variable' => 'resolvedRole',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 247,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 249,
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
                  'variable' => 'annotationsAdapter',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 249,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotationsAdapter',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 249,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 249,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 249,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotationsAdapter',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 250,
                      'char' => 53,
                    ),
                    'name' => 'getMethod',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'controllerClass',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 250,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 250,
                        'char' => 79,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'actionName',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 250,
                            'char' => 92,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'Action',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 250,
                            'char' => 100,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 250,
                          'char' => 100,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 250,
                        'char' => 100,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 250,
                    'char' => 101,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 250,
                  'char' => 101,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 252,
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
                  'variable' => 'access',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 252,
                      'char' => 27,
                    ),
                    'name' => 'checkAnnotations',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 252,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 252,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'role',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 252,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 252,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 252,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 252,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 254,
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
                    'value' => 'access',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 254,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 254,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 254,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 254,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 255,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'activeArgumentsNumber',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 255,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 255,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 255,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 255,
                    'char' => 48,
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
                          'variable' => 'resolvedRole',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 256,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'resolvedRole',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 256,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 256,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 256,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 258,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'resolvedRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 258,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 258,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 258,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 258,
                        'char' => 49,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'resolvedRole',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 259,
                            'char' => 52,
                          ),
                          'value' => 'singleRole',
                          'reverse' => 0,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 260,
                                  'char' => 30,
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'singleRole',
                                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                              'line' => 261,
                                              'char' => 40,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '!',
                                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                              'line' => 261,
                                              'char' => 44,
                                            ),
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 261,
                                            'char' => 44,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'controllerName',
                                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                            'line' => 261,
                                            'char' => 61,
                                          ),
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 261,
                                          'char' => 61,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '!',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 261,
                                          'char' => 65,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 261,
                                        'char' => 65,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'actionName',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 261,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 261,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 261,
                                    'char' => 77,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'access',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 263,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 263,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 263,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 264,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 265,
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
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 266,
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'resolvedRole',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 267,
                                          'char' => 38,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '!',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 267,
                                          'char' => 42,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 267,
                                        'char' => 42,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'controllerName',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 267,
                                        'char' => 59,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 267,
                                      'char' => 59,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '!',
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 267,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 267,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'actionName',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 267,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 267,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 267,
                                'char' => 75,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'access',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 269,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 269,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 269,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 270,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 271,
                      'char' => 13,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 272,
                          'char' => 22,
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '*!',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 273,
                                    'char' => 24,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'controllerName',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 273,
                                    'char' => 41,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 273,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '!',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 273,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 273,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'actionName',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 273,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 273,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 273,
                            'char' => 57,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'access',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 275,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 275,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 275,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 276,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 277,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 279,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 279,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 280,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 240,
          'last-line' => 282,
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
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 283,
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
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 284,
                'char' => 36,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 284,
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
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 286,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 286,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 288,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 288,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 290,
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
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 290,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 290,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 290,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 290,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 292,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 292,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 292,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 292,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 293,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 294,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 296,
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
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 296,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 296,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 296,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 296,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 296,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 296,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 301,
              'char' => 11,
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
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 302,
                                  'char' => 24,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 302,
                                  'char' => 26,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 302,
                                'char' => 28,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '!',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 302,
                                'char' => 32,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 302,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'explodedKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 302,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 302,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 302,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 302,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '!*',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 303,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 303,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 303,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 303,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 303,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 305,
              'char' => 10,
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
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 305,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 305,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 305,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 306,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 307,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 313,
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
                                'type' => 'string',
                                'value' => '*!',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 314,
                                'char' => 16,
                              ),
                              'right' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'explodedKey',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 314,
                                  'char' => 29,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 314,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 314,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 314,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '!',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 314,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 314,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'explodedKey',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 314,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 314,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 315,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 315,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 315,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 315,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 315,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 317,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'access',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 317,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 317,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 317,
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
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 318,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 319,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 325,
              'char' => 11,
            ),
            8 => 
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
                              'type' => 'string',
                              'value' => '*!',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 326,
                              'char' => 16,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'explodedKey',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 326,
                                'char' => 29,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 326,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 326,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 326,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '!*',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 327,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 327,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 327,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 327,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 327,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 329,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'access',
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 329,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 330,
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
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 286,
                'char' => 15,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 287,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
            'line' => 287,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 282,
          'last-line' => 332,
          'char' => 22,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleAnnotation',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'annotation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 332,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 332,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 332,
              'char' => 78,
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
                  'variable' => 'numberArguments',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 334,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'annotationRoles',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 334,
                  'char' => 45,
                ),
                2 => 
                array (
                  'variable' => 'roleIntersect',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 334,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 336,
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
                  'variable' => 'numberArguments',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 336,
                      'char' => 54,
                    ),
                    'name' => 'numberArguments',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 336,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 336,
                  'char' => 72,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'activeArgumentsNumber',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'numberArguments',
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 337,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 337,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 339,
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
                  'type' => 'variable',
                  'value' => 'numberArguments',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 339,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 339,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                'line' => 339,
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
                      'variable' => 'annotationRoles',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'annotation',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 340,
                            'char' => 46,
                          ),
                          'name' => 'getArguments',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 340,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 340,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 340,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 340,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 342,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'annotationRoles',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 342,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 342,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 342,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 342,
                    'char' => 48,
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
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'role',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 343,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 343,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 343,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 343,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'in_array',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'role',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 343,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 343,
                              'char' => 58,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'annotationRoles',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 343,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 343,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 343,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 343,
                        'char' => 77,
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
                              'property' => 'resolvedRole',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'role',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 344,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 344,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 346,
                          'char' => 26,
                        ),
                        1 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'access',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 346,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 347,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
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
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 347,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 347,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 347,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 347,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'roleIntersect',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'array_intersect',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'role',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 348,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 348,
                                        'char' => 61,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'annotationRoles',
                                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                          'line' => 348,
                                          'char' => 78,
                                        ),
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 348,
                                        'char' => 78,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 348,
                                    'char' => 79,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 348,
                                  'char' => 79,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 350,
                              'char' => 22,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'bool',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'roleIntersect',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 350,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 350,
                                'char' => 45,
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
                                      'property' => 'resolvedRole',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'roleIntersect',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 351,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 351,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 353,
                                  'char' => 30,
                                ),
                                1 => 
                                array (
                                  'type' => 'return',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'access',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 353,
                                    'char' => 38,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 354,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 355,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 355,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'access',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 355,
                              'char' => 34,
                            ),
                            'right' => 
                            array (
                              'type' => 'bool',
                              'value' => 'false',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 355,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 355,
                            'char' => 42,
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
                                  'property' => 'resolvedRole',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'role',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 356,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 356,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 358,
                              'char' => 26,
                            ),
                            1 => 
                            array (
                              'type' => 'return',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 358,
                                'char' => 32,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 359,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 361,
                          'char' => 22,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 361,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 361,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 362,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
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
                            'value' => 'annotationRoles',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 362,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 362,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 362,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 362,
                        'char' => 55,
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
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'role',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 363,
                                  'char' => 33,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 363,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'string',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 363,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 363,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'annotationRoles',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 363,
                                'char' => 62,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'role',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 363,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 363,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 363,
                            'char' => 69,
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
                                  'property' => 'resolvedRole',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'role',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 364,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 364,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 366,
                              'char' => 26,
                            ),
                            1 => 
                            array (
                              'type' => 'return',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'access',
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 366,
                                'char' => 34,
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 367,
                              'char' => 17,
                            ),
                          ),
                          'elseif_statements' => 
                          array (
                            0 => 
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
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 367,
                                      'char' => 39,
                                    ),
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 367,
                                    'char' => 39,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'array',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 367,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 367,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'in_array',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'annotationRoles',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 367,
                                        'char' => 74,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 367,
                                      'char' => 74,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'role',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 367,
                                        'char' => 80,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 367,
                                      'char' => 80,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 367,
                                  'char' => 82,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 367,
                                'char' => 82,
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
                                      'property' => 'resolvedRole',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'annotationRoles',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 368,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 368,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 370,
                                  'char' => 26,
                                ),
                                1 => 
                                array (
                                  'type' => 'return',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'access',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 370,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 371,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 371,
                              'char' => 24,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'access',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 371,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'false',
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 371,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                'line' => 371,
                                'char' => 42,
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
                                      'property' => 'resolvedRole',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'role',
                                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                        'line' => 372,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                      'line' => 372,
                                      'char' => 50,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 374,
                                  'char' => 26,
                                ),
                                1 => 
                                array (
                                  'type' => 'return',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                    'line' => 374,
                                    'char' => 32,
                                  ),
                                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                                  'line' => 375,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 377,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 377,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 377,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 378,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 378,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
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
                              'value' => 'Allowed or denied role must be provided as string or array of roles.',
                              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                              'line' => 381,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 381,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 381,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 382,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 383,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'numberArguments',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 383,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 383,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 383,
                    'char' => 40,
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
                          'property' => 'resolvedRole',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'role',
                            'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                            'line' => 384,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 384,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 386,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'access',
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 386,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                      'line' => 387,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 387,
                  'char' => 14,
                ),
              ),
              'else_statements' => 
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
                          'value' => 'Allow or deny annotation expect one or none arguments',
                          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                          'line' => 390,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                        'line' => 390,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                    'line' => 390,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
                  'line' => 391,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
              'line' => 392,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
          'line' => 332,
          'last-line' => 393,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Firewall/Adapter/Annotations.zep',
    'line' => 24,
    'char' => 5,
  ),
);