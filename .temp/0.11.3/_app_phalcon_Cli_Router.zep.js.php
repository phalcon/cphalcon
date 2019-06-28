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
    'file' => '/app/phalcon/Cli/Router.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/Router.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Cli/Router.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Cli/Router.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Cli/Router.zep',
        'line' => 14,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Cli/Router.zep',
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
        'name' => 'Phalcon\\Cli\\Router\\Route',
        'file' => '/app/phalcon/Cli/Router.zep',
        'line' => 15,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Cli/Router.zep',
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
        'name' => 'Phalcon\\Cli\\Router\\Exception',
        'file' => '/app/phalcon/Cli/Router.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Cli/Router.zep',
    'line' => 37,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Cli\\Router is the standard framework router. Routing is the process
 * of taking a command-line arguments and decomposing it into parameters to
 * determine which module, task, and action of that task should receive the
 * request.
 *
 *```php
 * $router = new \\Phalcon\\Cli\\Router();
 *
 * $router->handle(
 *     [
 *         "module" => "main",
 *         "task"   => "videos",
 *         "action" => "process",
 *     ]
 * );
 *
 * echo $router->getTaskName();
 *```
 *',
    'file' => '/app/phalcon/Cli/Router.zep',
    'line' => 38,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Router',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Cli/Router.zep',
        'line' => 39,
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
          'name' => 'action',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 42,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 44,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultAction',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 44,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 46,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultModule',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 46,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 50,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultParams',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 51,
            'char' => 33,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 53,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultTask',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 53,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 55,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'matchedRoute',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 57,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'matches',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 59,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'module',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 63,
          'char' => 6,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'params',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 64,
            'char' => 26,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 66,
          'char' => 13,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'routes',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 68,
          'char' => 13,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'task',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 70,
          'char' => 13,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'wasMatched',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 70,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 74,
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
              'name' => 'defaultRoutes',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 75,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 75,
              'char' => 58,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'routes',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 77,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 79,
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
                  'variable' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 79,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 79,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 81,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'defaultRoutes',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 81,
                'char' => 26,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'routes',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Route',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '#^(?::delimiter)?([a-zA-Z0-9\\\\_\\\\-]+)[:delimiter]{0,1}$#',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 86,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 86,
                            'char' => 73,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'task',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 88,
                                    'char' => 25,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 89,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 89,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 90,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 90,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 90,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 90,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 92,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'routes',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Route',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '#^(?::delimiter)?([a-zA-Z0-9\\\\_\\\\-]+):delimiter([a-zA-Z0-9\\\\.\\\\_]+)(:delimiter.*)*$#',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 93,
                              'char' => 101,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 93,
                            'char' => 101,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'task',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 95,
                                    'char' => 25,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 95,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 95,
                                  'char' => 30,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'action',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 96,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 96,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 96,
                                  'char' => 30,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'params',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 97,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '3',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 98,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 98,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 99,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 99,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 99,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 99,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 100,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 102,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routes',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 102,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 102,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Cli\\Router constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 76,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 75,
          'last-line' => 113,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'pattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 114,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'paths',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 114,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 114,
              'char' => 54,
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
                  'variable' => 'route',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 116,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 118,
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
                  'variable' => 'route',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Route',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 118,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 118,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 118,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 118,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 118,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 118,
                  'char' => 46,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'route',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 119,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 119,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 121,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'route',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 121,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 122,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router
     *
     *```php
     * $router->add("/about", "About::main");
     *```
     *
     * @param string|array paths
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 115,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 115,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 115,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 114,
          'last-line' => 126,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActionName',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 129,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'action',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 129,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 129,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns processed action name
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 128,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 128,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 127,
          'last-line' => 134,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 137,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 137,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 137,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 138,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 136,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 135,
          'last-line' => 142,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMatchedRoute',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 145,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'matchedRoute',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 145,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 145,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the route that matches the handled URI
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 144,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 144,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 143,
          'last-line' => 150,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMatches',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 153,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'matches',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 153,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 153,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the sub expressions in the regular expression matched
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 152,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 152,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 151,
          'last-line' => 158,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModuleName',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 161,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'module',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 161,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 161,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 162,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns processed module name
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 159,
          'last-line' => 166,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 169,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 169,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 169,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 170,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns processed extra params
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 168,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 168,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 167,
          'last-line' => 176,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRouteById',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 177,
              'char' => 40,
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
                  'variable' => 'route',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 179,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 181,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 181,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 181,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 181,
                'char' => 35,
              ),
              'value' => 'route',
              'reverse' => 0,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'route',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 182,
                        'char' => 22,
                      ),
                      'name' => 'getRouteId',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 182,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'id',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 182,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 182,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'route',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 183,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 184,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 185,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 187,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 187,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 188,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a route object by its id
     *
     * @param int id
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 177,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 177,
                'char' => 62,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 178,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 178,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 177,
          'last-line' => 192,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRouteByName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 193,
              'char' => 48,
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
                  'variable' => 'route',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 195,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 197,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 197,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 197,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 197,
                'char' => 35,
              ),
              'value' => 'route',
              'reverse' => 0,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'route',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 198,
                        'char' => 22,
                      ),
                      'name' => 'getName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 198,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 198,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 198,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'route',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 199,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 200,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 201,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 203,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 203,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 204,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a route object by its name
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 193,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 193,
                'char' => 70,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 194,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 194,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 193,
          'last-line' => 208,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRoutes',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 211,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 211,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 211,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 212,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the routes defined in the router
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
                  'value' => 'Route',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 210,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 210,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 210,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 209,
          'last-line' => 216,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTaskName',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 219,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'task',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 219,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 219,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 220,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns processed task name
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 218,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 218,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 217,
          'last-line' => 226,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'handle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 227,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 227,
              'char' => 44,
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
                  'variable' => 'moduleName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'taskName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 53,
                ),
                4 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 60,
                ),
                5 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 67,
                ),
                6 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 229,
                  'char' => 76,
                ),
                7 => 
                array (
                  'variable' => 'routeFound',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 23,
                ),
                8 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 32,
                ),
                9 => 
                array (
                  'variable' => 'paths',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 39,
                ),
                10 => 
                array (
                  'variable' => 'beforeMatch',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 52,
                ),
                11 => 
                array (
                  'variable' => 'converters',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 64,
                ),
                12 => 
                array (
                  'variable' => 'converter',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 230,
                  'char' => 75,
                ),
                13 => 
                array (
                  'variable' => 'part',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 231,
                  'char' => 17,
                ),
                14 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 231,
                  'char' => 27,
                ),
                15 => 
                array (
                  'variable' => 'matchPosition',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 231,
                  'char' => 42,
                ),
                16 => 
                array (
                  'variable' => 'strParams',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 231,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 233,
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
                  'variable' => 'routeFound',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 233,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 233,
                  'char' => 31,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parts',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 234,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 234,
                  'char' => 23,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'params',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 235,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 235,
                  'char' => 24,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 236,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 236,
                  'char' => 27,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'wasMatched',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 237,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 237,
                  'char' => 37,
                ),
                5 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'matchedRoute',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 238,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 238,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 240,
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
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 240,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 240,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 240,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 240,
                'char' => 38,
              ),
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
                      'type' => 'list',
                      'left' => 
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
                              'value' => 'arguments',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 241,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 241,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 241,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 241,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'arguments',
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 241,
                            'char' => 68,
                          ),
                          'right' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 241,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 241,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 241,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 241,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 241,
                    'char' => 76,
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
                              'value' => 'Arguments must be an array or string',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 242,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 242,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 242,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 243,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 245,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 245,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routes',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 245,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 245,
                    'char' => 47,
                  ),
                  'value' => 'route',
                  'reverse' => 1,
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
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'route',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 249,
                              'char' => 37,
                            ),
                            'name' => 'getCompiledPattern',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 249,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 249,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 251,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'memstr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'pattern',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 251,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 251,
                            'char' => 34,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '^',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 251,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 251,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 251,
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
                              'variable' => 'routeFound',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'preg_match',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'pattern',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 252,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 252,
                                    'char' => 56,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arguments',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 252,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 252,
                                    'char' => 67,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'matches',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 252,
                                      'char' => 76,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 252,
                                    'char' => 76,
                                  ),
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 252,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 252,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 253,
                          'char' => 17,
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
                              'variable' => 'routeFound',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 254,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'arguments',
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 254,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 254,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 254,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 255,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 260,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'routeFound',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 260,
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
                              'variable' => 'beforeMatch',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'route',
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 261,
                                  'char' => 45,
                                ),
                                'name' => 'getBeforeMatch',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 261,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 261,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 263,
                          'char' => 22,
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
                              'value' => 'beforeMatch',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 263,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 263,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 263,
                            'char' => 45,
                          ),
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
                                          'value' => 'beforeMatch',
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 267,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 267,
                                        'char' => 61,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 267,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 267,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 267,
                                'char' => 63,
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
                                          'value' => 'Before-Match callback is not callable in matched route',
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 270,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 270,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 270,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 271,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 276,
                              'char' => 27,
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
                                  'variable' => 'routeFound',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'call_user_func_array',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'beforeMatch',
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 277,
                                          'char' => 40,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 277,
                                        'char' => 40,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'array',
                                          'left' => 
                                          array (
                                            0 => 
                                            array (
                                              'value' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'arguments',
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 279,
                                                'char' => 42,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 279,
                                              'char' => 42,
                                            ),
                                            1 => 
                                            array (
                                              'value' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'route',
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 280,
                                                'char' => 38,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 280,
                                              'char' => 38,
                                            ),
                                            2 => 
                                            array (
                                              'value' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'this',
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 282,
                                                'char' => 29,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 282,
                                              'char' => 29,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 283,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 283,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 283,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 283,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 284,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 285,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 287,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'routeFound',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 287,
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
                              'variable' => 'paths',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'route',
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 291,
                                  'char' => 39,
                                ),
                                'name' => 'getPaths',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 291,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 291,
                              'char' => 50,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'parts',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'paths',
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 292,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 292,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 297,
                          'char' => 22,
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
                                'value' => 'matches',
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 297,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 297,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 297,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 297,
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
                                  'variable' => 'converters',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'route',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 301,
                                      'char' => 48,
                                    ),
                                    'name' => 'getConverters',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 301,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 301,
                                  'char' => 64,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 303,
                              'char' => 27,
                            ),
                            1 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'paths',
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 303,
                                'char' => 53,
                              ),
                              'key' => 'part',
                              'value' => 'position',
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
                                      'value' => 'matchPosition',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 304,
                                      'char' => 71,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'matches',
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 304,
                                        'char' => 60,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'position',
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 304,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 304,
                                      'char' => 71,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 304,
                                    'char' => 71,
                                  ),
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
                                          'value' => 'converter',
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 308,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'converters',
                                            'file' => '/app/phalcon/Cli/Router.zep',
                                            'line' => 308,
                                            'char' => 63,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'part',
                                            'file' => '/app/phalcon/Cli/Router.zep',
                                            'line' => 308,
                                            'char' => 68,
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 308,
                                          'char' => 70,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 308,
                                        'char' => 70,
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
                                              'variable' => 'parts',
                                              'index-expr' => 
                                              array (
                                                0 => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'part',
                                                  'file' => '/app/phalcon/Cli/Router.zep',
                                                  'line' => 309,
                                                  'char' => 51,
                                                ),
                                              ),
                                              'expr' => 
                                              array (
                                                'type' => 'fcall',
                                                'name' => 'call_user_func_array',
                                                'call-type' => 1,
                                                'parameters' => 
                                                array (
                                                  0 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'converter',
                                                      'file' => '/app/phalcon/Cli/Router.zep',
                                                      'line' => 310,
                                                      'char' => 50,
                                                    ),
                                                    'file' => '/app/phalcon/Cli/Router.zep',
                                                    'line' => 310,
                                                    'char' => 50,
                                                  ),
                                                  1 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'array',
                                                      'left' => 
                                                      array (
                                                        0 => 
                                                        array (
                                                          'value' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'matchPosition',
                                                            'file' => '/app/phalcon/Cli/Router.zep',
                                                            'line' => 311,
                                                            'char' => 55,
                                                          ),
                                                          'file' => '/app/phalcon/Cli/Router.zep',
                                                          'line' => 311,
                                                          'char' => 55,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Cli/Router.zep',
                                                      'line' => 312,
                                                      'char' => 37,
                                                    ),
                                                    'file' => '/app/phalcon/Cli/Router.zep',
                                                    'line' => 312,
                                                    'char' => 37,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 312,
                                                'char' => 38,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 312,
                                              'char' => 38,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 313,
                                          'char' => 33,
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
                                              'variable' => 'parts',
                                              'index-expr' => 
                                              array (
                                                0 => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'part',
                                                  'file' => '/app/phalcon/Cli/Router.zep',
                                                  'line' => 317,
                                                  'char' => 51,
                                                ),
                                              ),
                                              'expr' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'matchPosition',
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 317,
                                                'char' => 68,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 317,
                                              'char' => 68,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 318,
                                          'char' => 33,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 319,
                                      'char' => 29,
                                    ),
                                  ),
                                  'else_statements' => 
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
                                          'value' => 'converter',
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 323,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'converters',
                                            'file' => '/app/phalcon/Cli/Router.zep',
                                            'line' => 323,
                                            'char' => 63,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'part',
                                            'file' => '/app/phalcon/Cli/Router.zep',
                                            'line' => 323,
                                            'char' => 68,
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 323,
                                          'char' => 70,
                                        ),
                                        'file' => '/app/phalcon/Cli/Router.zep',
                                        'line' => 323,
                                        'char' => 70,
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
                                              'variable' => 'parts',
                                              'index-expr' => 
                                              array (
                                                0 => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'part',
                                                  'file' => '/app/phalcon/Cli/Router.zep',
                                                  'line' => 324,
                                                  'char' => 51,
                                                ),
                                              ),
                                              'expr' => 
                                              array (
                                                'type' => 'fcall',
                                                'name' => 'call_user_func_array',
                                                'call-type' => 1,
                                                'parameters' => 
                                                array (
                                                  0 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'converter',
                                                      'file' => '/app/phalcon/Cli/Router.zep',
                                                      'line' => 325,
                                                      'char' => 50,
                                                    ),
                                                    'file' => '/app/phalcon/Cli/Router.zep',
                                                    'line' => 325,
                                                    'char' => 50,
                                                  ),
                                                  1 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'array',
                                                      'left' => 
                                                      array (
                                                        0 => 
                                                        array (
                                                          'value' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'position',
                                                            'file' => '/app/phalcon/Cli/Router.zep',
                                                            'line' => 326,
                                                            'char' => 50,
                                                          ),
                                                          'file' => '/app/phalcon/Cli/Router.zep',
                                                          'line' => 326,
                                                          'char' => 50,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Cli/Router.zep',
                                                      'line' => 327,
                                                      'char' => 37,
                                                    ),
                                                    'file' => '/app/phalcon/Cli/Router.zep',
                                                    'line' => 327,
                                                    'char' => 37,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Cli/Router.zep',
                                                'line' => 327,
                                                'char' => 38,
                                              ),
                                              'file' => '/app/phalcon/Cli/Router.zep',
                                              'line' => 327,
                                              'char' => 38,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Cli/Router.zep',
                                          'line' => 328,
                                          'char' => 33,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 329,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 330,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 335,
                              'char' => 27,
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
                                  'property' => 'matches',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'matches',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 335,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 335,
                                  'char' => 52,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 336,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 338,
                          'char' => 23,
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
                              'property' => 'matchedRoute',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'route',
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 338,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 338,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 340,
                          'char' => 25,
                        ),
                        3 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 341,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 342,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 348,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routeFound',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 348,
                    'char' => 27,
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
                          'property' => 'wasMatched',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 349,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 349,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 350,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'wasMatched',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 351,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 351,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 356,
                      'char' => 19,
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
                          'property' => 'module',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 356,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'defaultModule',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 356,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 356,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 356,
                          'char' => 55,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'task',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 357,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'defaultTask',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 357,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 357,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 357,
                          'char' => 51,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'action',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 358,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'defaultAction',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 358,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 358,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 358,
                          'char' => 55,
                        ),
                        3 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 359,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'defaultParams',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 359,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 359,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 359,
                          'char' => 55,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 361,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 361,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 362,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 363,
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
                      'variable' => 'parts',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 364,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 364,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 367,
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
                  'variable' => 'moduleName',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 367,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 367,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'taskName',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 368,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 368,
                  'char' => 28,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'actionName',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 369,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 369,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 374,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'moduleName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 374,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parts',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 374,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'module',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 374,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 374,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 374,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 375,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'module',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 375,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 375,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 376,
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
                      'variable' => 'moduleName',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 377,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultModule',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 377,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 377,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 377,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 378,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 383,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'taskName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 383,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parts',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 383,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'task',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 383,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 383,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 383,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 384,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'task',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 384,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 384,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 385,
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
                      'variable' => 'taskName',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 386,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultTask',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 386,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 386,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 386,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 387,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 392,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'actionName',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 392,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parts',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 392,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'action',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 392,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 392,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 392,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 393,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'action',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 393,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 393,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 394,
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
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 395,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultAction',
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 395,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 395,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 395,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 396,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 401,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 401,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parts',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 401,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'params',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 401,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 401,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 401,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 402,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 402,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 402,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 402,
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
                          'variable' => 'strParams',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'substr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'cast',
                                  'left' => 'string',
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'params',
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 404,
                                    'char' => 36,
                                  ),
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 404,
                                  'char' => 36,
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 404,
                                'char' => 36,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Cli/Router.zep',
                                  'line' => 406,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 406,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 406,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 406,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 408,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'strParams',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 408,
                        'char' => 30,
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
                              'variable' => 'params',
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
                                      'type' => 'scall',
                                      'dynamic-class' => 0,
                                      'class' => 'Route',
                                      'dynamic' => 0,
                                      'name' => 'getDelimiter',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 409,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 409,
                                    'char' => 63,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'strParams',
                                      'file' => '/app/phalcon/Cli/Router.zep',
                                      'line' => 409,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Cli/Router.zep',
                                    'line' => 409,
                                    'char' => 74,
                                  ),
                                ),
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 409,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 409,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 410,
                          'char' => 17,
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
                              'variable' => 'params',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Cli/Router.zep',
                                'line' => 411,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 411,
                              'char' => 36,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Router.zep',
                          'line' => 412,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 413,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 415,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 415,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'params',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 415,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 415,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 416,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 418,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'count',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 418,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 418,
                    'char' => 24,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 418,
                'char' => 26,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_merge',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 419,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 419,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parts',
                              'file' => '/app/phalcon/Cli/Router.zep',
                              'line' => 419,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Cli/Router.zep',
                            'line' => 419,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 419,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 419,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 420,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 421,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 421,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 422,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 424,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'module',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'moduleName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 424,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 424,
                  'char' => 38,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'task',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'taskName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 425,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 425,
                  'char' => 34,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'action',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'actionName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 426,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 426,
                  'char' => 38,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'params',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 427,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 427,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 428,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles routing information received from command-line arguments
     *
     * @param array arguments
     *',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 227,
          'last-line' => 432,
          'char' => 19,
        ),
        13 => 
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
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 433,
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
                  'property' => 'defaultAction',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'actionName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 435,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 435,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 436,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default action name
     *',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 433,
          'last-line' => 440,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultModule',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'moduleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 441,
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
                  'property' => 'defaultModule',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'moduleName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 443,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 443,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 444,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the name of the default module
     *',
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 441,
          'last-line' => 459,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaults',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaults',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 460,
              'char' => 48,
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
                  'variable' => 'module',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 462,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'task',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 462,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'action',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 462,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 462,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 465,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'module',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 465,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 465,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'module',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 465,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 465,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 465,
                'char' => 43,
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
                      'property' => 'defaultModule',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'module',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 466,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 466,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 467,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 470,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'task',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 470,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 470,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'task',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 470,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 470,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 470,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'defaultTask',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'task',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 471,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 471,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 472,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 475,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'action',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 475,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 475,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'action',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 475,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 475,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 475,
                'char' => 43,
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
                      'property' => 'defaultAction',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'action',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 476,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 476,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 477,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 480,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 480,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 480,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'params',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 480,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 480,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 480,
                'char' => 43,
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
                      'property' => 'defaultParams',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Cli/Router.zep',
                        'line' => 481,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Router.zep',
                      'line' => 481,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 482,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 484,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 484,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 485,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an array of default paths. If a route is missing a path the router
     * will use the defined here. This method must not be used to set a 404
     * route
     *
     *```php
     * $router->setDefaults(
     *     [
     *         "module" => "common",
     *         "action" => "index",
     *     ]
     * );
     *```
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
                  'value' => 'Router',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 461,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 461,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 461,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 460,
          'last-line' => 489,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultTask',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'taskName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 490,
              'char' => 51,
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
                  'property' => 'defaultTask',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'taskName',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 492,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 492,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 493,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default controller name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 491,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 490,
          'last-line' => 497,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 498,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 498,
              'char' => 50,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Cli/Router.zep',
                    'line' => 500,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 500,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 501,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 499,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 498,
          'last-line' => 505,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'wasMatched',
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
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 508,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'wasMatched',
                  'file' => '/app/phalcon/Cli/Router.zep',
                  'line' => 508,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 508,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Cli/Router.zep',
              'line' => 509,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if the router matches any of the defined routes
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
                'file' => '/app/phalcon/Cli/Router.zep',
                'line' => 507,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router.zep',
            'line' => 507,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Router.zep',
          'line' => 506,
          'last-line' => 510,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cli/Router.zep',
      'line' => 38,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cli/Router.zep',
    'line' => 38,
    'char' => 5,
  ),
);