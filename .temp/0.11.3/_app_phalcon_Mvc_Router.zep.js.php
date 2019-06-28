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
    'file' => '/app/phalcon/Mvc/Router.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\Route',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\Exception',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 15,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Http\\RequestInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 16,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\GroupInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\RouteInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 18,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 19,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 20,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
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
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 21,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
    'line' => 50,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router
 *
 * Phalcon\\Mvc\\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the
 * base URL) and decomposing it into parameters to determine which module,
 * controller, and action of that controller should receive the request
 *
 * ```php
 * use Phalcon\\Mvc\\Router;
 *
 * $router = new Router();
 *
 * $router->add(
 *     "/documentation/{chapter}/{name}\\.{type:[a-z]+}",
 *     [
 *         "controller" => "documentation",
 *         "action"     => "show",
 *     ]
 * );
 *
 * $router->handle(
 *     "/documentation/1/examples.html"
 * );
 *
 * echo $router->getControllerName();
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Router.zep',
    'line' => 51,
    'char' => 5,
  ),
  12 => 
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
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 51,
        'char' => 48,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'RouterInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 51,
        'char' => 65,
      ),
      2 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Mvc/Router.zep',
        'line' => 52,
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
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 56,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 57,
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
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 58,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'controller',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 58,
            'char' => 32,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 59,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultAction',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 60,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultController',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 61,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultModule',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 62,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultNamespace',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 63,
          'char' => 13,
        ),
        7 => 
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
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 63,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 64,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'eventsManager',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 65,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'keyRouteNames',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 65,
            'char' => 34,
          ),
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 65,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 65,
              'char' => 45,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
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
          'name' => 'keyRouteIds',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 66,
            'char' => 32,
          ),
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 66,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 66,
              'char' => 43,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 67,
          'char' => 13,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'matchedRoute',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 68,
          'char' => 13,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'matches',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 69,
          'char' => 13,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'module',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 69,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 70,
          'char' => 13,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'namespaceName',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 70,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 71,
          'char' => 13,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'notFoundPaths',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 72,
          'char' => 13,
        ),
        16 => 
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
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 72,
            'char' => 26,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 73,
          'char' => 13,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'removeExtraSlashes',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 74,
          'char' => 13,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'routes',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 75,
          'char' => 13,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'uriSource',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 76,
          'char' => 13,
        ),
        20 => 
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
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 76,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 80,
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
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 81,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 81,
              'char' => 59,
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
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 83,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 83,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 85,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'defaultRoutes',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 85,
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
                              'value' => '#^/([\\\\w0-9\\\\_\\\\-]+)[/]{0,1}$#u',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 92,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 92,
                            'char' => 48,
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
                                    'value' => 'controller',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 94,
                                    'char' => 31,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 95,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 95,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 96,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 96,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 96,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 96,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 98,
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
                              'value' => '#^/([\\\\w0-9\\\\_\\\\-]+)/([\\\\w0-9\\\\.\\\\_]+)(/.*)*$#u',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 99,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 99,
                            'char' => 64,
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
                                    'value' => 'controller',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 101,
                                    'char' => 31,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 101,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 101,
                                  'char' => 34,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'action',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 102,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 102,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 102,
                                  'char' => 34,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'params',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 103,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '3',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 104,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 104,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 105,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 105,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 105,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 105,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 106,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 108,
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
                  'property' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routes',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 108,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 108,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 109,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Router constructor
     *',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 81,
          'last-line' => 132,
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 133,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 133,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 133,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'httpMethods',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 133,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 133,
              'char' => 82,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 133,
                  'char' => 120,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 133,
                  'char' => 120,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 133,
                'char' => 120,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 133,
              'char' => 120,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 135,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 140,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 140,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 140,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 140,
                        'char' => 45,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'httpMethods',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 140,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 140,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 140,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 140,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 142,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 142,
                  'char' => 14,
                ),
                'name' => 'attach',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'route',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 142,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 142,
                    'char' => 27,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 142,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 142,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 142,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 144,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'route',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 144,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router without any HTTP constraint
     *
     *```php
     * use Phalcon\\Mvc\\Router;
     *
     * $router->add("/about", "About::index");
     *
     * $router->add(
     *     "/about",
     *     "About::index",
     *     ["GET", "POST"]
     * );
     *
     * $router->add(
     *     "/about",
     *     "About::index",
     *     ["GET", "POST"],
     *     Router::POSITION_FIRST
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 134,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 133,
          'last-line' => 149,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addConnect',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 150,
              'char' => 47,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 150,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 150,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 150,
                  'char' => 103,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 150,
                  'char' => 103,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 150,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 150,
              'char' => 103,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 152,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 152,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 152,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 152,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 152,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'CONNECT',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 152,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 152,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 152,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 152,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 152,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is CONNECT
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 151,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 151,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 150,
          'last-line' => 157,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addDelete',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 158,
              'char' => 46,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 158,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 158,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 158,
                  'char' => 102,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 158,
                  'char' => 102,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 158,
                'char' => 102,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 158,
              'char' => 102,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 160,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 160,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 160,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 160,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 160,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'DELETE',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 160,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 160,
                    'char' => 48,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 160,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 160,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 160,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is DELETE
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 159,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 159,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 158,
          'last-line' => 165,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addGet',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 166,
              'char' => 43,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 166,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 166,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 166,
                  'char' => 99,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 166,
                  'char' => 99,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 166,
                'char' => 99,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 166,
              'char' => 99,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 168,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 168,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 168,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 168,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 168,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'GET',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 168,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 168,
                    'char' => 45,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 168,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 168,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 168,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 169,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is GET
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 167,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 167,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 167,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 166,
          'last-line' => 173,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addHead',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 174,
              'char' => 44,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 174,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 174,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 174,
                  'char' => 100,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 174,
                  'char' => 100,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 174,
                'char' => 100,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 174,
              'char' => 100,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 176,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 176,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 176,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 176,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 176,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HEAD',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 176,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 176,
                    'char' => 46,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 176,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 176,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 176,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 177,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is HEAD
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 175,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 174,
          'last-line' => 181,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addOptions',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 182,
              'char' => 47,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 182,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 182,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 182,
                  'char' => 103,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 182,
                  'char' => 103,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 182,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 182,
              'char' => 103,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 184,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 184,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 184,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 184,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 184,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'OPTIONS',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 184,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 184,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 184,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 184,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 184,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 185,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Add a route to the router that only match if the HTTP method is OPTIONS
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 183,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 183,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 183,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 182,
          'last-line' => 189,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPatch',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 190,
              'char' => 45,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 190,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 190,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 190,
                  'char' => 101,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 190,
                  'char' => 101,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 190,
                'char' => 101,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 190,
              'char' => 101,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 192,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 192,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 192,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 192,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 192,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PATCH',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 192,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 192,
                    'char' => 47,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 192,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 192,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 192,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 193,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PATCH
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 191,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 191,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 191,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 190,
          'last-line' => 197,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPost',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 198,
              'char' => 44,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 198,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 198,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 198,
                  'char' => 100,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 198,
                  'char' => 100,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 198,
                'char' => 100,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 198,
              'char' => 100,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 200,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 200,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 200,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 200,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 200,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'POST',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 200,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 200,
                    'char' => 46,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 200,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 200,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 200,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 201,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is POST
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 199,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 198,
          'last-line' => 206,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPurge',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 207,
              'char' => 45,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 207,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 207,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 207,
                  'char' => 101,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 207,
                  'char' => 101,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 207,
                'char' => 101,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 207,
              'char' => 101,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 209,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 209,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 209,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 209,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 209,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PURGE',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 209,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 209,
                    'char' => 47,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 209,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 209,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 209,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 210,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PURGE
     * (Squid and Varnish support)
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 208,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 208,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 208,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 207,
          'last-line' => 214,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPut',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 215,
              'char' => 43,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 215,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 215,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 215,
                  'char' => 99,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 215,
                  'char' => 99,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 215,
                'char' => 99,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 215,
              'char' => 99,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 217,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 217,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 217,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 217,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 217,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PUT',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 217,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 217,
                    'char' => 45,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 217,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 217,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 217,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 218,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PUT
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 216,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 216,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 216,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 215,
          'last-line' => 222,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addTrace',
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 223,
              'char' => 45,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 223,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 223,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 223,
                  'char' => 101,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 223,
                  'char' => 101,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 223,
                'char' => 101,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 223,
              'char' => 101,
            ),
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 225,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 225,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 225,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 225,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 225,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'TRACE',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 225,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 225,
                    'char' => 47,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 225,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 225,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 225,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 226,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is TRACE
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 224,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 224,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 224,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 223,
          'last-line' => 246,
          'char' => 19,
        ),
        12 => 
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
              'name' => 'route',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'RouteInterface',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 247,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 247,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Router',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 247,
                  'char' => 88,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 247,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 247,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 247,
              'char' => 88,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'position',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 249,
                'char' => 25,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 250,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'POSITION_LAST',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 250,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 250,
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
                          'assign-type' => 'object-property-append',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'routes',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'route',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 251,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 251,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 252,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 253,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 253,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 253,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'POSITION_FIRST',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 253,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 253,
                    'char' => 38,
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
                          'property' => 'routes',
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
                                  'type' => 'array',
                                  'left' => 
                                  array (
                                    0 => 
                                    array (
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'route',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 254,
                                        'char' => 54,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 254,
                                      'char' => 54,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 254,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 254,
                                'char' => 55,
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
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 254,
                                    'char' => 62,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'routes',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 254,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 254,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 254,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 254,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 254,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 255,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 256,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 256,
                  'char' => 19,
                ),
                2 => 
                array (
                  'type' => 'default',
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
                              'value' => 'Invalid route position',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 257,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 257,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 257,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 258,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 260,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 260,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 261,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Attach Route object to the routes stack.
     *
     * ```php
     * use Phalcon\\Mvc\\Router;
     * use Phalcon\\Mvc\\Router\\Route;
     *
     * class CustomRoute extends Route {
     *      // ...
     * }
     *
     * $router = new Router();
     *
     * $router->attach(
     *     new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
     *     Router::POSITION_FIRST
     * );
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 248,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 248,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 248,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 247,
          'last-line' => 265,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                  'property' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 268,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 268,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 269,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes all the pre-defined routes
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 267,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 266,
          'last-line' => 273,
          'char' => 19,
        ),
        14 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 276,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 276,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 276,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 277,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 275,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 275,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 275,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 274,
          'last-line' => 281,
          'char' => 19,
        ),
        15 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 284,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 284,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 284,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 285,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 283,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 283,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 283,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 282,
          'last-line' => 289,
          'char' => 19,
        ),
        16 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 292,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'action',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 292,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 292,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 293,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the processed action name
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 291,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 291,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 290,
          'last-line' => 297,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerName',
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 300,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'controller',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 300,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 300,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 301,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the processed controller name
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 299,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 299,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 298,
          'last-line' => 305,
          'char' => 19,
        ),
        18 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 308,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'matchedRoute',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 308,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 308,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 309,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 307,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 307,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 307,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 306,
          'last-line' => 313,
          'char' => 19,
        ),
        19 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 316,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'matches',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 316,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 316,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 317,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 315,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 315,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 314,
          'last-line' => 321,
          'char' => 19,
        ),
        20 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 324,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'module',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 324,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 324,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 325,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the processed module name
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 323,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 323,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 322,
          'last-line' => 329,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNamespaceName',
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 332,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'namespaceName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 332,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 332,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 333,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the processed namespace name
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 331,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 331,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 330,
          'last-line' => 337,
          'char' => 19,
        ),
        22 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 340,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 340,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 340,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 341,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the processed parameters
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 339,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 339,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 338,
          'last-line' => 345,
          'char' => 19,
        ),
        23 => 
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 346,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 348,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'routeId',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 348,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 348,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 350,
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
                  'value' => 'key',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 350,
                  'char' => 45,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 350,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyRouteIds',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 350,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 350,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 350,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 350,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 350,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 351,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'routes',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 351,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 351,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 351,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 351,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 352,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 354,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 354,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 354,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 354,
                'char' => 40,
              ),
              'key' => 'key',
              'value' => 'route',
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
                      'variable' => 'routeId',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 355,
                          'char' => 33,
                        ),
                        'name' => 'getRouteId',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 355,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 355,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 356,
                  'char' => 15,
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
                      'property' => 'keyRouteIds',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'routeId',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 356,
                          'char' => 42,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 356,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 356,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 358,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routeId',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 358,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'id',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 358,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 358,
                    'char' => 30,
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
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 359,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 360,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 361,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 363,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 363,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 364,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a route object by its id
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 346,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 346,
                'char' => 62,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 347,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 347,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 346,
          'last-line' => 368,
          'char' => 19,
        ),
        24 => 
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 369,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 371,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'routeName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 371,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 371,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 373,
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
                  'value' => 'key',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 373,
                  'char' => 49,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 373,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyRouteNames',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 373,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 373,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 373,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 373,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 373,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 374,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'routes',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 374,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 374,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 374,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 374,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 375,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 377,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 377,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 377,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 377,
                'char' => 40,
              ),
              'key' => 'key',
              'value' => 'route',
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
                      'variable' => 'routeName',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 378,
                          'char' => 35,
                        ),
                        'name' => 'getName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 378,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 378,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 380,
                  'char' => 14,
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
                        'value' => 'routeName',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 380,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 380,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 380,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'keyRouteNames',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'routeName',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 381,
                              'char' => 50,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 381,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 381,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 383,
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
                          'type' => 'variable',
                          'value' => 'routeName',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 383,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 383,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 383,
                        'char' => 38,
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
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 384,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 385,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 386,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 387,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 389,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 389,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 390,
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 369,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 369,
                'char' => 70,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 369,
          'last-line' => 394,
          'char' => 19,
        ),
        25 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 397,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 397,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 397,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 398,
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 396,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 396,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 396,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 395,
          'last-line' => 407,
          'char' => 19,
        ),
        26 => 
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
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 408,
              'char' => 39,
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
                  'variable' => 'request',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'currentHostName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'routeFound',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 410,
                  'char' => 73,
                ),
                6 => 
                array (
                  'variable' => 'notFoundPaths',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 26,
                ),
                7 => 
                array (
                  'variable' => 'vnamespace',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 38,
                ),
                8 => 
                array (
                  'variable' => 'module',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 46,
                ),
                9 => 
                array (
                  'variable' => 'controller',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 59,
                ),
                10 => 
                array (
                  'variable' => 'action',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 67,
                ),
                11 => 
                array (
                  'variable' => 'paramsStr',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 411,
                  'char' => 78,
                ),
                12 => 
                array (
                  'variable' => 'strParams',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 22,
                ),
                13 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 29,
                ),
                14 => 
                array (
                  'variable' => 'methods',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 38,
                ),
                15 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 49,
                ),
                16 => 
                array (
                  'variable' => 'hostname',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 59,
                ),
                17 => 
                array (
                  'variable' => 'regexHostName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 412,
                  'char' => 74,
                ),
                18 => 
                array (
                  'variable' => 'matched',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 20,
                ),
                19 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 29,
                ),
                20 => 
                array (
                  'variable' => 'handledUri',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 41,
                ),
                21 => 
                array (
                  'variable' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 54,
                ),
                22 => 
                array (
                  'variable' => 'paths',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 61,
                ),
                23 => 
                array (
                  'variable' => 'converters',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 73,
                ),
                24 => 
                array (
                  'variable' => 'part',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 413,
                  'char' => 79,
                ),
                25 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 414,
                  'char' => 21,
                ),
                26 => 
                array (
                  'variable' => 'matchPosition',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 414,
                  'char' => 36,
                ),
                27 => 
                array (
                  'variable' => 'converter',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 414,
                  'char' => 47,
                ),
                28 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 414,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 416,
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
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'parse_url',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 416,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 416,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_URL_PATH',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 416,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 416,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 416,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 416,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 421,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 421,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'removeExtraSlashes',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 421,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 421,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uri',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 421,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '/',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 421,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 421,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 421,
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
                      'variable' => 'handledUri',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'rtrim',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 422,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 422,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '/',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 422,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 422,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 422,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 422,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 423,
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
                      'variable' => 'handledUri',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 424,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 424,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 425,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 427,
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
                  'variable' => 'request',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 427,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 427,
                  'char' => 27,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'currentHostName',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 428,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 428,
                  'char' => 35,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'routeFound',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 429,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 429,
                  'char' => 31,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parts',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 430,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 430,
                  'char' => 23,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'params',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 431,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 431,
                  'char' => 24,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 432,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 432,
                  'char' => 27,
                ),
                6 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'wasMatched',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 433,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 433,
                  'char' => 37,
                ),
                7 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'matchedRoute',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 434,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 434,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 436,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 436,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 436,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 436,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 436,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 438,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 438,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 438,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 438,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 438,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 439,
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
                          'value' => 'router:beforeCheckRoutes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 439,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 439,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 439,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 439,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 439,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 440,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 445,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 445,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 445,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 445,
                'char' => 43,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 446,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 446,
                      'char' => 28,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'matches',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 447,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 447,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 452,
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
                      'variable' => 'methods',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 452,
                          'char' => 33,
                        ),
                        'name' => 'getHttpMethods',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 452,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 452,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 454,
                  'char' => 14,
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
                      'value' => 'methods',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 454,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 454,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 454,
                    'char' => 33,
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
                          'type' => 'variable',
                          'value' => 'request',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 458,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 458,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 458,
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
                              'variable' => 'container',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'DiInterface',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 459,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 459,
                                    'char' => 56,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 459,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 459,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 459,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 459,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 461,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'unlikely',
                            'left' => 
                            array (
                              'type' => 'not-equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'container',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 461,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 461,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'object',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 461,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 461,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 461,
                            'char' => 60,
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
                                            'value' => 'the \'request\' service',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 465,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 465,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 466,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 466,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 466,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 467,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 469,
                          'char' => 23,
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
                              'variable' => 'request',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'RequestInterface',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 469,
                                  'char' => 83,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 469,
                                    'char' => 64,
                                  ),
                                  'name' => 'getShared',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'request',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 469,
                                        'char' => 82,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 469,
                                      'char' => 82,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 469,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 469,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 469,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 470,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 475,
                      'char' => 18,
                    ),
                    1 => 
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
                            'value' => 'request',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 475,
                            'char' => 28,
                          ),
                          'name' => 'isMethod',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'methods',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 475,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 475,
                              'char' => 45,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 475,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 475,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 475,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 475,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 475,
                        'char' => 63,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 477,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 478,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 483,
                  'char' => 15,
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
                      'variable' => 'hostname',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 483,
                          'char' => 34,
                        ),
                        'name' => 'getHostName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 483,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 483,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 485,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hostname',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 485,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 485,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 485,
                    'char' => 34,
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
                          'type' => 'variable',
                          'value' => 'request',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 489,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 489,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 489,
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
                              'variable' => 'container',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'DiInterface',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 490,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 490,
                                    'char' => 56,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 490,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 490,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 490,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 490,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 492,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'unlikely',
                            'left' => 
                            array (
                              'type' => 'not-equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'container',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 492,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 492,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'object',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 492,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 492,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 492,
                            'char' => 60,
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
                                            'value' => 'the \'request\' service',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 496,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 496,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 497,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 497,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 497,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 498,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 500,
                          'char' => 23,
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
                              'variable' => 'request',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'RequestInterface',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 500,
                                  'char' => 83,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 500,
                                    'char' => 64,
                                  ),
                                  'name' => 'getShared',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'request',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 500,
                                        'char' => 82,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 500,
                                      'char' => 82,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 500,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 500,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 500,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 501,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 506,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'currentHostName',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 506,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 506,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 506,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'currentHostName',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'request',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 507,
                                  'char' => 51,
                                ),
                                'name' => 'getHttpHost',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 507,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 507,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 508,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 513,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'currentHostName',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 513,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 513,
                        'char' => 37,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 515,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 521,
                      'char' => 18,
                    ),
                    3 => 
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
                              'value' => 'hostname',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 521,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 521,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '(',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 521,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 521,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 521,
                        'char' => 40,
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
                              'name' => 'memstr',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'hostname',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 522,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 522,
                                  'char' => 40,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '#',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 522,
                                    'char' => 43,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 522,
                                  'char' => 43,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 522,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 522,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'regexHostName',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '#^',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 523,
                                      'char' => 48,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'hostname',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 523,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 523,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 523,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 525,
                              'char' => 26,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'not',
                                'left' => 
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
                                        'value' => 'hostname',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 525,
                                        'char' => 44,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 525,
                                      'char' => 44,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ':',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 525,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 525,
                                      'char' => 47,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 525,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 525,
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
                                      'operator' => 'concat-assign',
                                      'variable' => 'regexHostName',
                                      'expr' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '(:[[:digit:]]+)?',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 526,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 526,
                                      'char' => 65,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 527,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 529,
                              'char' => 27,
                            ),
                            2 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'regexHostName',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '$#i',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 529,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 529,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 530,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'regexHostName',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'hostname',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 531,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 531,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 532,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 534,
                          'char' => 23,
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
                              'variable' => 'matched',
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
                                      'value' => 'regexHostName',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 534,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 534,
                                    'char' => 59,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'currentHostName',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 534,
                                      'char' => 76,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 534,
                                    'char' => 76,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 534,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 534,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 535,
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
                              'variable' => 'matched',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'currentHostName',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 536,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'hostname',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 536,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 536,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 536,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 537,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 539,
                      'char' => 18,
                    ),
                    4 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'matched',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 539,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 539,
                        'char' => 29,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 541,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 542,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 544,
                  'char' => 14,
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 544,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 544,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 544,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 544,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 545,
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
                              'value' => 'router:beforeCheckRoute',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 545,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 545,
                            'char' => 60,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 545,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 545,
                            'char' => 66,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'route',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 545,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 545,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 545,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 546,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 551,
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
                      'variable' => 'pattern',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 551,
                          'char' => 33,
                        ),
                        'name' => 'getCompiledPattern',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 551,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 551,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 553,
                  'char' => 14,
                ),
                7 => 
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 553,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 553,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '^',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 553,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 553,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 553,
                    'char' => 35,
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
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 554,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 554,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'handledUri',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 554,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 554,
                                'char' => 64,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'matches',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 554,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 554,
                                'char' => 73,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 554,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 554,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 555,
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
                          'variable' => 'routeFound',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'pattern',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 556,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handledUri',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 556,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 556,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 556,
                          'char' => 55,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 557,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 562,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routeFound',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 562,
                    'char' => 27,
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
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 563,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 563,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 563,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 563,
                        'char' => 51,
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
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 564,
                              'char' => 35,
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
                                  'value' => 'router:matchedRoute',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 564,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 564,
                                'char' => 60,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 564,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 564,
                                'char' => 66,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'route',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 564,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 564,
                                'char' => 73,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 564,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 565,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 567,
                      'char' => 19,
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
                          'variable' => 'beforeMatch',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'route',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 567,
                              'char' => 41,
                            ),
                            'name' => 'getBeforeMatch',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 567,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 567,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 569,
                      'char' => 18,
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
                          'value' => 'beforeMatch',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 569,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 569,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 569,
                        'char' => 41,
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
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 573,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 573,
                                    'char' => 57,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 573,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 573,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 573,
                            'char' => 59,
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
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 576,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 576,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 576,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 577,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 582,
                          'char' => 23,
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
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 583,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 583,
                                    'char' => 36,
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
                                            'value' => 'handledUri',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 585,
                                            'char' => 39,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 585,
                                          'char' => 39,
                                        ),
                                        1 => 
                                        array (
                                          'value' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'route',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 586,
                                            'char' => 34,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 586,
                                          'char' => 34,
                                        ),
                                        2 => 
                                        array (
                                          'value' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 588,
                                            'char' => 25,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 588,
                                          'char' => 25,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 589,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 589,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 589,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 589,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 590,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 592,
                      'char' => 13,
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
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 593,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 593,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 593,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 593,
                        'char' => 51,
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'eventsManager',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 594,
                                  'char' => 52,
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
                                      'value' => 'router:notMatchedRoute',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 594,
                                      'char' => 80,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 594,
                                    'char' => 80,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 594,
                                      'char' => 86,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 594,
                                    'char' => 86,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'route',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 594,
                                      'char' => 93,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 594,
                                    'char' => 93,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 594,
                                'char' => 94,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 594,
                              'char' => 94,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 595,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 596,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 598,
                  'char' => 14,
                ),
                9 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routeFound',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 598,
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
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 602,
                              'char' => 35,
                            ),
                            'name' => 'getPaths',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 602,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 602,
                          'char' => 46,
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
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 603,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 603,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 608,
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
                            'value' => 'matches',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 608,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 608,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 608,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 608,
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
                              'variable' => 'converters',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'route',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 612,
                                  'char' => 44,
                                ),
                                'name' => 'getConverters',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 612,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 612,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 614,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'paths',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 614,
                            'char' => 49,
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
                                'type' => 'unlikely',
                                'left' => 
                                array (
                                  'type' => 'not-equals',
                                  'left' => 
                                  array (
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'part',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 615,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 615,
                                    'char' => 50,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'string',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 615,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 615,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 615,
                                'char' => 59,
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
                                            'value' => 'Wrong key in paths: ',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 616,
                                            'char' => 70,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'part',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 616,
                                            'char' => 76,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 616,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 616,
                                        'char' => 76,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 616,
                                    'char' => 77,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 617,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 619,
                              'char' => 26,
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
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'position',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 619,
                                      'char' => 45,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 619,
                                    'char' => 45,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'string',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 619,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 619,
                                  'char' => 55,
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
                                      'value' => 'position',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 619,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 619,
                                    'char' => 74,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'integer',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 619,
                                    'char' => 84,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 619,
                                  'char' => 84,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 619,
                                'char' => 84,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'continue',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 621,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 623,
                              'char' => 26,
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
                                  'value' => 'matchPosition',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 623,
                                  'char' => 67,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'matches',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 623,
                                    'char' => 56,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'position',
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 623,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 623,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 623,
                                'char' => 67,
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
                                        'value' => 'converters',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 627,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 627,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'array',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 627,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 627,
                                    'char' => 59,
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
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 628,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'converters',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 628,
                                            'char' => 63,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'part',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 628,
                                            'char' => 68,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 628,
                                          'char' => 70,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 628,
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
                                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                                  'line' => 629,
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
                                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                                      'line' => 630,
                                                      'char' => 50,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                                    'line' => 630,
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
                                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                                            'line' => 631,
                                                            'char' => 55,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                                          'line' => 631,
                                                          'char' => 55,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                                      'line' => 632,
                                                      'char' => 37,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                                    'line' => 632,
                                                    'char' => 37,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router.zep',
                                                'line' => 632,
                                                'char' => 38,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router.zep',
                                              'line' => 632,
                                              'char' => 38,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 634,
                                          'char' => 44,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'continue',
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 635,
                                          'char' => 33,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 636,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 641,
                                  'char' => 31,
                                ),
                                1 => 
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
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 641,
                                          'char' => 43,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'matchPosition',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 641,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 641,
                                      'char' => 60,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 642,
                                  'char' => 25,
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
                                        'value' => 'converters',
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 646,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 646,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'array',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 646,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 646,
                                    'char' => 59,
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
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 647,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'converters',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 647,
                                            'char' => 63,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'part',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 647,
                                            'char' => 68,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 647,
                                          'char' => 70,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 647,
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
                                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                                  'line' => 648,
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
                                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                                      'line' => 649,
                                                      'char' => 50,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                                    'line' => 649,
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
                                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                                            'line' => 650,
                                                            'char' => 50,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                                          'line' => 650,
                                                          'char' => 50,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                                      'line' => 651,
                                                      'char' => 37,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                                    'line' => 651,
                                                    'char' => 37,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router.zep',
                                                'line' => 651,
                                                'char' => 38,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router.zep',
                                              'line' => 651,
                                              'char' => 38,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 652,
                                          'char' => 33,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 653,
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
                                        'type' => 'equals',
                                        'left' => 
                                        array (
                                          'type' => 'typeof',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'position',
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 658,
                                            'char' => 53,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 658,
                                          'char' => 53,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'integer',
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 658,
                                          'char' => 63,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 658,
                                        'char' => 63,
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
                                              'file' => '/app/phalcon/Mvc/Router.zep',
                                              'line' => 659,
                                              'char' => 48,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'part',
                                              'file' => '/app/phalcon/Mvc/Router.zep',
                                              'line' => 659,
                                              'char' => 53,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router.zep',
                                            'line' => 659,
                                            'char' => 54,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 660,
                                          'char' => 33,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 661,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 662,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 663,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 668,
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
                              'property' => 'matches',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'matches',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 668,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 668,
                              'char' => 48,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 669,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 671,
                      'char' => 19,
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
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 671,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 671,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 673,
                      'char' => 21,
                    ),
                    3 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 674,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 675,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 680,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'routeFound',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 680,
                'char' => 23,
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
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 681,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 681,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 682,
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
                      'property' => 'wasMatched',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 683,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 683,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 684,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 689,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'routeFound',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 689,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 689,
                'char' => 24,
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
                      'variable' => 'notFoundPaths',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 690,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'notFoundPaths',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 690,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 690,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 690,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 692,
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
                      'value' => 'notFoundPaths',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 692,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 692,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 692,
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
                          'variable' => 'parts',
                          'expr' => 
                          array (
                            'type' => 'scall',
                            'dynamic-class' => 0,
                            'class' => 'Route',
                            'dynamic' => 0,
                            'name' => 'getRoutePaths',
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'notFoundPaths',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 693,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 693,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 693,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 693,
                          'char' => 64,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'routeFound',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 694,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 694,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 695,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 696,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 701,
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
                  'property' => 'namespaceName',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 701,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultNamespace',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 701,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 701,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 701,
                  'char' => 57,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 702,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultModule',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 702,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 702,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 702,
                  'char' => 47,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'controller',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 703,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultController',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 703,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 703,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 703,
                  'char' => 55,
                ),
                3 => 
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 704,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultAction',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 704,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 704,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 704,
                  'char' => 47,
                ),
                4 => 
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 705,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultParams',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 705,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 705,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 705,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 707,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'routeFound',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 707,
                'char' => 23,
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
                      'value' => 'vnamespace',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 711,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 711,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'namespace',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 711,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 711,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 711,
                    'char' => 51,
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
                          'name' => 'is_numeric',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'vnamespace',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 712,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 712,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 712,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 712,
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
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'namespaceName',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'vnamespace',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 713,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 713,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 714,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 716,
                      'char' => 21,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 716,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'namespace',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 716,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 716,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 717,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 722,
                  'char' => 14,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 722,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 722,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'module',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 722,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 722,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 722,
                    'char' => 44,
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
                          'name' => 'is_numeric',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'module',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 723,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 723,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 723,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 723,
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
                              'property' => 'module',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'module',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 724,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 724,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 725,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 727,
                      'char' => 21,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 727,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'module',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 727,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 727,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 728,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 733,
                  'char' => 14,
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
                      'value' => 'controller',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 733,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 733,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'controller',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 733,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 733,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 733,
                    'char' => 52,
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
                          'name' => 'is_numeric',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'controller',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 734,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 734,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 734,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 734,
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
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'controller',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'controller',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 735,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 735,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 736,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 738,
                      'char' => 21,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 738,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'controller',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 738,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 738,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 739,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 744,
                  'char' => 14,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 744,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 744,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'action',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 744,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 744,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 744,
                    'char' => 44,
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
                          'name' => 'is_numeric',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'action',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 745,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 745,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 745,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 745,
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
                              'property' => 'action',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'action',
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 746,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 746,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 747,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 749,
                      'char' => 21,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 749,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 749,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 749,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 750,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 755,
                  'char' => 14,
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
                      'value' => 'paramsStr',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 755,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parts',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 755,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 755,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 755,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 755,
                    'char' => 47,
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
                            'value' => 'paramsStr',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 756,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 756,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 756,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 756,
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
                              'variable' => 'strParams',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'trim',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paramsStr',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 757,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 757,
                                    'char' => 51,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '/',
                                      'file' => '/app/phalcon/Mvc/Router.zep',
                                      'line' => 757,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 757,
                                    'char' => 54,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 757,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 757,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 759,
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
                              'value' => 'strParams',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 759,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 759,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 759,
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
                                          'type' => 'string',
                                          'value' => '/',
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 760,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 760,
                                        'char' => 47,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'strParams',
                                          'file' => '/app/phalcon/Mvc/Router.zep',
                                          'line' => 760,
                                          'char' => 58,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router.zep',
                                        'line' => 760,
                                        'char' => 58,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router.zep',
                                    'line' => 760,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 760,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 761,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 762,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 764,
                      'char' => 21,
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 764,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 764,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 764,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 765,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 767,
                  'char' => 14,
                ),
                5 => 
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
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 767,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 767,
                        'char' => 28,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 767,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'params',
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
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 768,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 768,
                                'char' => 54,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router.zep',
                                  'line' => 768,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/Router.zep',
                                'line' => 768,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 768,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 768,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 769,
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
                          'property' => 'params',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parts',
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 770,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 770,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 771,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 772,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 774,
              'char' => 10,
            ),
            11 => 
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 774,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 774,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 774,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 774,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 775,
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
                          'value' => 'router:afterCheckRoutes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 775,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 775,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 775,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 775,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 775,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 776,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 777,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles routing information received from the rewrite engine
     *
     *```php
     * // Passing a URL
     * $router->handle("/posts/edit/1");
     *```
     *',
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 408,
          'last-line' => 781,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isExactControllerName',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 784,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 785,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether controller name should not be mangled
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 783,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 783,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 782,
          'last-line' => 789,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'mount',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'group',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'GroupInterface',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 790,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 790,
              'char' => 49,
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
                  'variable' => 'groupRoutes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'hostname',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 55,
                ),
                4 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 62,
                ),
                5 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 792,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 794,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 794,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 794,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 794,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 794,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 796,
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 796,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 796,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 796,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 796,
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
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 797,
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
                          'value' => 'router:beforeMount',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 797,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 797,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 797,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 797,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'group',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 797,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 797,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 797,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 798,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 800,
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
                  'variable' => 'groupRoutes',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 800,
                      'char' => 33,
                    ),
                    'name' => 'getRoutes',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 800,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 800,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 802,
              'char' => 10,
            ),
            4 => 
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
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'groupRoutes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 802,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 802,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 802,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 802,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 802,
                'char' => 41,
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
                          'value' => 'The group of routes does not contain any routes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 805,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 805,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 805,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 806,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 811,
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
                  'variable' => 'beforeMatch',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 811,
                      'char' => 33,
                    ),
                    'name' => 'getBeforeMatch',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 811,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 811,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 813,
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
                  'value' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 813,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 813,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 813,
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
                    'value' => 'groupRoutes',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 814,
                    'char' => 38,
                  ),
                  'value' => 'route',
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
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 815,
                          'char' => 23,
                        ),
                        'name' => 'beforeMatch',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'beforeMatch',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 815,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 815,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 815,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 816,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 817,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 820,
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
                  'variable' => 'hostname',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'group',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 820,
                      'char' => 30,
                    ),
                    'name' => 'getHostName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 820,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 820,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 822,
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
                  'value' => 'hostname',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 822,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 822,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 822,
                'char' => 30,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'groupRoutes',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 823,
                    'char' => 38,
                  ),
                  'value' => 'route',
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
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 824,
                          'char' => 23,
                        ),
                        'name' => 'setHostName',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'hostname',
                              'file' => '/app/phalcon/Mvc/Router.zep',
                              'line' => 824,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Router.zep',
                            'line' => 824,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 824,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 825,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 826,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 828,
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
                  'variable' => 'routes',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 828,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routes',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 828,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 828,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 828,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 830,
              'char' => 11,
            ),
            10 => 
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
                          'value' => 'routes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 830,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 830,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'groupRoutes',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 830,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 830,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 830,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 830,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 832,
              'char' => 14,
            ),
            11 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 832,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 833,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Mounts a group of routes in the router
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 791,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 791,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 791,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 790,
          'last-line' => 838,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notFound',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'paths',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 839,
              'char' => 39,
            ),
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
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 841,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 841,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 841,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 841,
                      'char' => 45,
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
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 841,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 841,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 841,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 841,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 841,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 841,
                  'char' => 71,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 841,
                'char' => 71,
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
                          'value' => 'The not-found paths must be an array or string',
                          'file' => '/app/phalcon/Mvc/Router.zep',
                          'line' => 844,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 844,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 844,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 845,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 847,
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
                  'property' => 'notFoundPaths',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paths',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 847,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 847,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 849,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 849,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 850,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a group of paths to be returned when none of the defined routes are
     * matched
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 840,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 840,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 840,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 839,
          'last-line' => 854,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'removeExtraSlashes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'remove',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 855,
              'char' => 52,
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
                  'property' => 'removeExtraSlashes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'remove',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 857,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 857,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 859,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 859,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 860,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set whether router must remove the extra slashes in the handled routes
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 856,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 856,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 856,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 855,
          'last-line' => 864,
          'char' => 19,
        ),
        31 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 865,
              'char' => 56,
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 867,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 867,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 869,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 869,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 870,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default action name
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 866,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 866,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 866,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 865,
          'last-line' => 874,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultController',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 875,
              'char' => 64,
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
                  'property' => 'defaultController',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controllerName',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 877,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 877,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 879,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 879,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 880,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default controller name
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 876,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 876,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 876,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 875,
          'last-line' => 884,
          'char' => 19,
        ),
        33 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 885,
              'char' => 56,
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 887,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 887,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 889,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 889,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 890,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the name of the default module
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 886,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 886,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 886,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 885,
          'last-line' => 894,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultNamespace',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'namespaceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 895,
              'char' => 62,
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
                  'property' => 'defaultNamespace',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'namespaceName',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 897,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 897,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 899,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 899,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 900,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the name of the default namespace
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 896,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 896,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 896,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 895,
          'last-line' => 915,
          'char' => 19,
        ),
        35 => 
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
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 916,
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
                  'variable' => 'namespaceName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 918,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'module',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 918,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'controller',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 918,
                  'char' => 46,
                ),
                3 => 
                array (
                  'variable' => 'action',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 918,
                  'char' => 54,
                ),
                4 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 918,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 921,
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
                  'value' => 'namespaceName',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 921,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 921,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'namespace',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 921,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 921,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 921,
                'char' => 53,
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
                      'property' => 'defaultNamespace',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'namespaceName',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 922,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 922,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 923,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 926,
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
                  'value' => 'module',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 926,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 926,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'module',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 926,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 926,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 926,
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
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 927,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 927,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 928,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 931,
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
                  'value' => 'controller',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 931,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 931,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'controller',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 931,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 931,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 931,
                'char' => 51,
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
                      'property' => 'defaultController',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'controller',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 932,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 932,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 933,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 936,
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
                  'value' => 'action',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 936,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 936,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'action',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 936,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 936,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 936,
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
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 937,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 937,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 938,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 941,
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
                  'value' => 'params',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 941,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 941,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 941,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 941,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 941,
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
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 942,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 942,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 943,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 945,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 945,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 946,
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
                  'value' => 'RouterInterface',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 917,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 917,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 917,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 916,
          'last-line' => 950,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaults',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'namespace',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 954,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 954,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultNamespace',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 954,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 954,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 954,
                    'char' => 47,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'module',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 955,
                      'char' => 19,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 955,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultModule',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 955,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 955,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 955,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'controller',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 956,
                      'char' => 23,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 956,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultController',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 956,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 956,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 956,
                    'char' => 48,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'action',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 957,
                      'char' => 19,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 957,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultAction',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 957,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 957,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 957,
                    'char' => 44,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 958,
                      'char' => 19,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 958,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultParams',
                        'file' => '/app/phalcon/Mvc/Router.zep',
                        'line' => 959,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Mvc/Router.zep',
                      'line' => 959,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 959,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 959,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 960,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of default parameters
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 952,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 952,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 951,
          'last-line' => 964,
          'char' => 19,
        ),
        37 => 
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 965,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 965,
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 967,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 967,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 968,
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
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 966,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 965,
          'last-line' => 972,
          'char' => 19,
        ),
        38 => 
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 973,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 973,
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
                    'file' => '/app/phalcon/Mvc/Router.zep',
                    'line' => 975,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 975,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 976,
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
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 974,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 973,
          'last-line' => 980,
          'char' => 19,
        ),
        39 => 
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
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 983,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'wasMatched',
                  'file' => '/app/phalcon/Mvc/Router.zep',
                  'line' => 983,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 983,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Router.zep',
              'line' => 984,
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
                'file' => '/app/phalcon/Mvc/Router.zep',
                'line' => 982,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 982,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 981,
          'last-line' => 985,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'POSITION_FIRST',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 53,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 54,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'POSITION_LAST',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Mvc/Router.zep',
            'line' => 54,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Router.zep',
          'line' => 56,
          'char' => 13,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router.zep',
      'line' => 51,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Router.zep',
    'line' => 51,
    'char' => 5,
  ),
);