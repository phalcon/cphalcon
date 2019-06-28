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
    'file' => '/app/phalcon/Mvc/Router/Route.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Router',
    'file' => '/app/phalcon/Mvc/Router/Route.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\Exception',
        'file' => '/app/phalcon/Mvc/Router/Route.zep',
        'line' => 13,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/Route.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router\\Route
 *
 * This class represents every route added to the router
 *',
    'file' => '/app/phalcon/Mvc/Router/Route.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Route',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RouteInterface',
        'file' => '/app/phalcon/Mvc/Router/Route.zep',
        'line' => 21,
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
          'name' => 'beforeMatch',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 23,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'compiledPattern',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 24,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'converters',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 25,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'group',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 26,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'hostname',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 27,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'id',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 27,
              'char' => 24,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 28,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'methods',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 29,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'match',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 30,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 31,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'paths',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 32,
          'char' => 13,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'pattern',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 33,
          'char' => 13,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'uniqueId',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 33,
            'char' => 34,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 37,
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
              'name' => 'pattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 38,
              'char' => 48,
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 38,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 38,
              'char' => 66,
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 38,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 38,
              'char' => 90,
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
                  'variable' => 'routeId',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 40,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'uniqueId',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 40,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 43,
              'char' => 12,
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 43,
                  'char' => 14,
                ),
                'name' => 'reConfigure',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 43,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 43,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 43,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 43,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 43,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 46,
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 46,
                  'char' => 14,
                ),
                'name' => 'via',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpMethods',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 46,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 46,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 46,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 49,
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
                  'variable' => 'uniqueId',
                  'expr' => 
                  array (
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 49,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uniqueId',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 49,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 49,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 49,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 52,
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
                  'variable' => 'routeId',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uniqueId',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 52,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 52,
                  'char' => 31,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'id',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routeId',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 53,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 53,
                  'char' => 31,
                ),
                2 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'uniqueId',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uniqueId',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 54,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 54,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 54,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 54,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Router\\Route constructor
     *',
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 38,
          'last-line' => 80,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'beforeMatch',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 81,
              'char' => 45,
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
                  'property' => 'beforeMatch',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'callback',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 83,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 83,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 85,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 85,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
     *
     *```php
     * $router->add(
     *     "/login",
     *     [
     *         "module"     => "admin",
     *         "controller" => "session",
     *     ]
     * )->beforeMatch(
     *     function ($uri, $route) {
     *         // Check if the request was made with Ajax
     *         if ($_SERVER["HTTP_X_REQUESTED_WITH"] === "xmlhttprequest") {
     *             return false;
     *         }
     *
     *         return true;
     *     }
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 82,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 82,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 81,
          'last-line' => 90,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'compilePattern',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 91,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'idPattern',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 93,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 96,
              'char' => 10,
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
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 96,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 96,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => ':',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 96,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 96,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 96,
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
                      'variable' => 'idPattern',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '/([\\\\w0-9\\\\_\\\\-]+)',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 98,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 98,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 101,
                  'char' => 14,
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 101,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 101,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:module',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 101,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 101,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 101,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:module',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 102,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 102,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'idPattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 102,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 102,
                                'char' => 62,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 102,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 102,
                                'char' => 71,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 102,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 102,
                          'char' => 72,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 106,
                  'char' => 14,
                ),
                2 => 
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 106,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 106,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:controller',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 106,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 106,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 106,
                    'char' => 46,
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
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:controller',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 107,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 107,
                                'char' => 55,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'idPattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 107,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 107,
                                'char' => 66,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 107,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 107,
                                'char' => 75,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 107,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 107,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 108,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 111,
                  'char' => 14,
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
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 111,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 111,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:namespace',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 111,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 111,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 111,
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
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:namespace',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 112,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 112,
                                'char' => 54,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'idPattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 112,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 112,
                                'char' => 65,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 112,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 112,
                                'char' => 74,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 112,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 112,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 113,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 116,
                  'char' => 14,
                ),
                4 => 
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 116,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 116,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:action',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 116,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 116,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 116,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:action',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 117,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 117,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'idPattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 117,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 117,
                                'char' => 62,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 117,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 117,
                                'char' => 71,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 117,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 117,
                          'char' => 72,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 118,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 121,
                  'char' => 14,
                ),
                5 => 
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 121,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 121,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:params',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 121,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 121,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 121,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:params',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 122,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 122,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '(/.*)*',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 122,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 122,
                                'char' => 59,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 122,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 122,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 122,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 122,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 123,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 126,
                  'char' => 14,
                ),
                6 => 
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 126,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 126,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/:int',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 126,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 126,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 126,
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
                          'variable' => 'pattern',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:int',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 127,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 127,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/([0-9]+)',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 127,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 127,
                                'char' => 59,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 127,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 127,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 127,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 127,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 128,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 129,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 135,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
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
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 135,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 135,
                      'char' => 26,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '(',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 135,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 135,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 135,
                  'char' => 32,
                ),
                'right' => 
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
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 135,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 135,
                      'char' => 48,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '[',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 135,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 135,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 135,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 135,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '#^',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 136,
                        'char' => 23,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 136,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 136,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '$#',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 136,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 136,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 139,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'pattern',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 139,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 140,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Replaces placeholders from pattern returning a valid PCRE regular expression
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 92,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 91,
          'last-line' => 144,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'convert',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 145,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'converter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 145,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'converters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 147,
                      'char' => 34,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'converter',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 147,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 147,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 149,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 149,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 150,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 146,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 145,
          'last-line' => 154,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'extractNamedParams',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 155,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'char',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'ch',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 157,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'prevCh',
                  'expr' => 
                  array (
                    'type' => 'char',
                    'value' => '\\0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 157,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 157,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 158,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'tmp',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 158,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 158,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 159,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'notValid',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 159,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 160,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'cursor',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'cursorVar',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'marker',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'bracketCount',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 160,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'parenthesesCount',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 160,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 78,
                ),
                5 => 
                array (
                  'variable' => 'foundPattern',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 160,
                    'char' => 96,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 160,
                  'char' => 96,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 161,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'intermediate',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 161,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 161,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'numberMatches',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 161,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 161,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 162,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 162,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 162,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'variable',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 162,
                  'char' => 37,
                ),
                3 => 
                array (
                  'variable' => 'regexp',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 162,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 164,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'strlen',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 164,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 164,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 164,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 164,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 164,
                'char' => 34,
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
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 165,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 166,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 168,
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
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 168,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 168,
                  'char' => 25,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'route',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 169,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 169,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 171,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'pattern',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 171,
                'char' => 35,
              ),
              'key' => 'cursor',
              'value' => 'ch',
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
                      'type' => 'variable',
                      'value' => 'parenthesesCount',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 172,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 172,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 172,
                    'char' => 38,
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
                          'type' => 'variable',
                          'value' => 'ch',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 173,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'char',
                          'value' => '{',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 173,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 173,
                        'char' => 29,
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
                              'type' => 'variable',
                              'value' => 'bracketCount',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 174,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 174,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 174,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'marker',
                                  'expr' => 
                                  array (
                                    'type' => 'add',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'cursor',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 175,
                                      'char' => 45,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 175,
                                      'char' => 48,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 175,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 175,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'intermediate',
                                  'expr' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 176,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 176,
                                  'char' => 45,
                                ),
                                2 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'notValid',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'false',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 177,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 177,
                                  'char' => 45,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 178,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 180,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'incr',
                              'variable' => 'bracketCount',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 180,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 181,
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
                              'type' => 'variable',
                              'value' => 'ch',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 181,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'char',
                              'value' => '}',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 181,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 181,
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
                                  'assign-type' => 'decr',
                                  'variable' => 'bracketCount',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 182,
                                  'char' => 39,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 184,
                              'char' => 22,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'greater',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'intermediate',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 184,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 184,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 184,
                                'char' => 41,
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
                                      'type' => 'variable',
                                      'value' => 'bracketCount',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 185,
                                      'char' => 42,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '0',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 185,
                                      'char' => 46,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 185,
                                    'char' => 46,
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
                                          'assign-type' => 'incr',
                                          'variable' => 'numberMatches',
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 186,
                                          'char' => 48,
                                        ),
                                        1 => 
                                        array (
                                          'assign-type' => 'variable',
                                          'operator' => 'assign',
                                          'variable' => 'variable',
                                          'expr' => 
                                          array (
                                            'type' => 'null',
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 187,
                                            'char' => 48,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 187,
                                          'char' => 48,
                                        ),
                                        2 => 
                                        array (
                                          'assign-type' => 'variable',
                                          'operator' => 'assign',
                                          'variable' => 'regexp',
                                          'expr' => 
                                          array (
                                            'type' => 'null',
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 188,
                                            'char' => 46,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 188,
                                          'char' => 46,
                                        ),
                                        3 => 
                                        array (
                                          'assign-type' => 'variable',
                                          'operator' => 'assign',
                                          'variable' => 'item',
                                          'expr' => 
                                          array (
                                            'type' => 'cast',
                                            'left' => 'string',
                                            'right' => 
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
                                                    'type' => 'variable',
                                                    'value' => 'pattern',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 189,
                                                    'char' => 63,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 189,
                                                  'char' => 63,
                                                ),
                                                1 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'marker',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 189,
                                                    'char' => 71,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 189,
                                                  'char' => 71,
                                                ),
                                                2 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'sub',
                                                    'left' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'cursor',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 189,
                                                      'char' => 80,
                                                    ),
                                                    'right' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'marker',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 189,
                                                      'char' => 88,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 189,
                                                    'char' => 88,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 189,
                                                  'char' => 88,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 189,
                                              'char' => 89,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 189,
                                            'char' => 89,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 189,
                                          'char' => 89,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 191,
                                      'char' => 31,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'for',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'item',
                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                        'line' => 191,
                                        'char' => 55,
                                      ),
                                      'key' => 'cursorVar',
                                      'value' => 'ch',
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
                                              'type' => 'variable',
                                              'value' => 'ch',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 192,
                                              'char' => 40,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'char',
                                              'value' => '\\0',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 192,
                                              'char' => 46,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 192,
                                            'char' => 46,
                                          ),
                                          'statements' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'break',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 194,
                                              'char' => 33,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 196,
                                          'char' => 34,
                                        ),
                                        1 => 
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
                                                'type' => 'variable',
                                                'value' => 'cursorVar',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 196,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'int',
                                                'value' => '0',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 196,
                                                'char' => 52,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 196,
                                              'char' => 52,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'not',
                                              'left' => 
                                              array (
                                                'type' => 'list',
                                                'left' => 
                                                array (
                                                  'type' => 'or',
                                                  'left' => 
                                                  array (
                                                    'type' => 'list',
                                                    'left' => 
                                                    array (
                                                      'type' => 'and',
                                                      'left' => 
                                                      array (
                                                        'type' => 'greater-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 60,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => 'a',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 66,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 196,
                                                        'char' => 66,
                                                      ),
                                                      'right' => 
                                                      array (
                                                        'type' => 'less-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 71,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => 'z',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 75,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 196,
                                                        'char' => 75,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 196,
                                                      'char' => 75,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 196,
                                                    'char' => 78,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'list',
                                                    'left' => 
                                                    array (
                                                      'type' => 'and',
                                                      'left' => 
                                                      array (
                                                        'type' => 'greater-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 84,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => 'A',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 90,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 196,
                                                        'char' => 90,
                                                      ),
                                                      'right' => 
                                                      array (
                                                        'type' => 'less-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 95,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => 'Z',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 196,
                                                          'char' => 99,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 196,
                                                        'char' => 99,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 196,
                                                      'char' => 99,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 196,
                                                    'char' => 100,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 196,
                                                  'char' => 100,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 196,
                                                'char' => 102,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 196,
                                              'char' => 102,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 196,
                                            'char' => 102,
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
                                                  'variable' => 'notValid',
                                                  'expr' => 
                                                  array (
                                                    'type' => 'bool',
                                                    'value' => 'true',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 197,
                                                    'char' => 56,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 197,
                                                  'char' => 56,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 199,
                                              'char' => 41,
                                            ),
                                            1 => 
                                            array (
                                              'type' => 'break',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 200,
                                              'char' => 33,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 202,
                                          'char' => 34,
                                        ),
                                        2 => 
                                        array (
                                          'type' => 'if',
                                          'expr' => 
                                          array (
                                            'type' => 'or',
                                            'left' => 
                                            array (
                                              'type' => 'or',
                                              'left' => 
                                              array (
                                                'type' => 'or',
                                                'left' => 
                                                array (
                                                  'type' => 'or',
                                                  'left' => 
                                                  array (
                                                    'type' => 'or',
                                                    'left' => 
                                                    array (
                                                      'type' => 'list',
                                                      'left' => 
                                                      array (
                                                        'type' => 'and',
                                                        'left' => 
                                                        array (
                                                          'type' => 'greater-equal',
                                                          'left' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'ch',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 40,
                                                          ),
                                                          'right' => 
                                                          array (
                                                            'type' => 'char',
                                                            'value' => 'a',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 46,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 46,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'less-equal',
                                                          'left' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'ch',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 51,
                                                          ),
                                                          'right' => 
                                                          array (
                                                            'type' => 'char',
                                                            'value' => 'z',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 55,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 55,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 202,
                                                        'char' => 55,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 202,
                                                      'char' => 58,
                                                    ),
                                                    'right' => 
                                                    array (
                                                      'type' => 'list',
                                                      'left' => 
                                                      array (
                                                        'type' => 'and',
                                                        'left' => 
                                                        array (
                                                          'type' => 'greater-equal',
                                                          'left' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'ch',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 64,
                                                          ),
                                                          'right' => 
                                                          array (
                                                            'type' => 'char',
                                                            'value' => 'A',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 70,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 70,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'less-equal',
                                                          'left' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'ch',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 75,
                                                          ),
                                                          'right' => 
                                                          array (
                                                            'type' => 'char',
                                                            'value' => 'Z',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 202,
                                                            'char' => 79,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 79,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 202,
                                                        'char' => 79,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 202,
                                                      'char' => 82,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 202,
                                                    'char' => 82,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'list',
                                                    'left' => 
                                                    array (
                                                      'type' => 'and',
                                                      'left' => 
                                                      array (
                                                        'type' => 'greater-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 88,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => '0',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 94,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 202,
                                                        'char' => 94,
                                                      ),
                                                      'right' => 
                                                      array (
                                                        'type' => 'less-equal',
                                                        'left' => 
                                                        array (
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 99,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => '9',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 202,
                                                          'char' => 102,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 202,
                                                        'char' => 102,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 202,
                                                      'char' => 102,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 202,
                                                    'char' => 105,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 202,
                                                  'char' => 105,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'equals',
                                                  'left' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'ch',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 202,
                                                    'char' => 111,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'char',
                                                    'value' => '-',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 202,
                                                    'char' => 117,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 202,
                                                  'char' => 117,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 202,
                                                'char' => 117,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'equals',
                                                'left' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'ch',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 202,
                                                  'char' => 123,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'char',
                                                  'value' => '_',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 202,
                                                  'char' => 129,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 202,
                                                'char' => 129,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 202,
                                              'char' => 129,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'equals',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'ch',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 202,
                                                'char' => 135,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'char',
                                                'value' => ':',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 202,
                                                'char' => 141,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 202,
                                              'char' => 141,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 202,
                                            'char' => 141,
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
                                                  'type' => 'variable',
                                                  'value' => 'ch',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 203,
                                                  'char' => 44,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'char',
                                                  'value' => ':',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 203,
                                                  'char' => 49,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 203,
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
                                                      'variable' => 'variable',
                                                      'expr' => 
                                                      array (
                                                        'type' => 'cast',
                                                        'left' => 'string',
                                                        'right' => 
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
                                                                'type' => 'variable',
                                                                'value' => 'item',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 204,
                                                                'char' => 76,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 204,
                                                              'char' => 76,
                                                            ),
                                                            1 => 
                                                            array (
                                                              'parameter' => 
                                                              array (
                                                                'type' => 'int',
                                                                'value' => '0',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 204,
                                                                'char' => 79,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 204,
                                                              'char' => 79,
                                                            ),
                                                            2 => 
                                                            array (
                                                              'parameter' => 
                                                              array (
                                                                'type' => 'variable',
                                                                'value' => 'cursorVar',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 204,
                                                                'char' => 90,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 204,
                                                              'char' => 90,
                                                            ),
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 204,
                                                          'char' => 91,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 204,
                                                        'char' => 91,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 204,
                                                      'char' => 91,
                                                    ),
                                                    1 => 
                                                    array (
                                                      'assign-type' => 'variable',
                                                      'operator' => 'assign',
                                                      'variable' => 'regexp',
                                                      'expr' => 
                                                      array (
                                                        'type' => 'cast',
                                                        'left' => 'string',
                                                        'right' => 
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
                                                                'type' => 'variable',
                                                                'value' => 'item',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 205,
                                                                'char' => 74,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 205,
                                                              'char' => 74,
                                                            ),
                                                            1 => 
                                                            array (
                                                              'parameter' => 
                                                              array (
                                                                'type' => 'add',
                                                                'left' => 
                                                                array (
                                                                  'type' => 'variable',
                                                                  'value' => 'cursorVar',
                                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                  'line' => 205,
                                                                  'char' => 86,
                                                                ),
                                                                'right' => 
                                                                array (
                                                                  'type' => 'int',
                                                                  'value' => '1',
                                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                  'line' => 205,
                                                                  'char' => 89,
                                                                ),
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 205,
                                                                'char' => 89,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 205,
                                                              'char' => 89,
                                                            ),
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 205,
                                                          'char' => 90,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 205,
                                                        'char' => 90,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 205,
                                                      'char' => 90,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 207,
                                                  'char' => 45,
                                                ),
                                                1 => 
                                                array (
                                                  'type' => 'break',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 208,
                                                  'char' => 37,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 209,
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
                                                  'assign-type' => 'variable',
                                                  'operator' => 'assign',
                                                  'variable' => 'notValid',
                                                  'expr' => 
                                                  array (
                                                    'type' => 'bool',
                                                    'value' => 'true',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 210,
                                                    'char' => 56,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 210,
                                                  'char' => 56,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 212,
                                              'char' => 41,
                                            ),
                                            1 => 
                                            array (
                                              'type' => 'break',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 213,
                                              'char' => 33,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 214,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 216,
                                      'char' => 30,
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
                                          'value' => 'notValid',
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 216,
                                          'char' => 42,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                        'line' => 216,
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
                                              'assign-type' => 'variable',
                                              'operator' => 'assign',
                                              'variable' => 'tmp',
                                              'expr' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'numberMatches',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 217,
                                                'char' => 56,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 217,
                                              'char' => 56,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 219,
                                          'char' => 34,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'if',
                                          'expr' => 
                                          array (
                                            'type' => 'and',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'variable',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 219,
                                              'char' => 46,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'regexp',
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 219,
                                              'char' => 55,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                            'line' => 219,
                                            'char' => 55,
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
                                                  'variable' => 'foundPattern',
                                                  'expr' => 
                                                  array (
                                                    'type' => 'int',
                                                    'value' => '0',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 220,
                                                    'char' => 57,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 220,
                                                  'char' => 57,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 222,
                                              'char' => 39,
                                            ),
                                            1 => 
                                            array (
                                              'type' => 'for',
                                              'expr' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'regexp',
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 222,
                                                'char' => 54,
                                              ),
                                              'value' => 'ch',
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
                                                      'type' => 'variable',
                                                      'value' => 'ch',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 223,
                                                      'char' => 48,
                                                    ),
                                                    'right' => 
                                                    array (
                                                      'type' => 'char',
                                                      'value' => '\\0',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 223,
                                                      'char' => 54,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 223,
                                                    'char' => 54,
                                                  ),
                                                  'statements' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'type' => 'break',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 225,
                                                      'char' => 41,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 227,
                                                  'char' => 42,
                                                ),
                                                1 => 
                                                array (
                                                  'type' => 'if',
                                                  'expr' => 
                                                  array (
                                                    'type' => 'not',
                                                    'left' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'foundPattern',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 227,
                                                      'char' => 58,
                                                    ),
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 227,
                                                    'char' => 58,
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
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 228,
                                                          'char' => 52,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => '(',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 228,
                                                          'char' => 57,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 228,
                                                        'char' => 57,
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
                                                              'variable' => 'foundPattern',
                                                              'expr' => 
                                                              array (
                                                                'type' => 'int',
                                                                'value' => '1',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 229,
                                                                'char' => 69,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 229,
                                                              'char' => 69,
                                                            ),
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 230,
                                                          'char' => 45,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 231,
                                                      'char' => 41,
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
                                                          'type' => 'variable',
                                                          'value' => 'ch',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 232,
                                                          'char' => 52,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'char',
                                                          'value' => ')',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 232,
                                                          'char' => 57,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 232,
                                                        'char' => 57,
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
                                                              'variable' => 'foundPattern',
                                                              'expr' => 
                                                              array (
                                                                'type' => 'int',
                                                                'value' => '2',
                                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                                'line' => 233,
                                                                'char' => 69,
                                                              ),
                                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                              'line' => 233,
                                                              'char' => 69,
                                                            ),
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 235,
                                                          'char' => 53,
                                                        ),
                                                        1 => 
                                                        array (
                                                          'type' => 'break',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 236,
                                                          'char' => 45,
                                                        ),
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 237,
                                                      'char' => 41,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 238,
                                                  'char' => 37,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 240,
                                              'char' => 38,
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
                                                  'value' => 'foundPattern',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 240,
                                                  'char' => 54,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '2',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 240,
                                                  'char' => 58,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 240,
                                                'char' => 58,
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
                                                      'variable' => 'route',
                                                      'expr' => 
                                                      array (
                                                        'type' => 'concat',
                                                        'left' => 
                                                        array (
                                                          'type' => 'concat',
                                                          'left' => 
                                                          array (
                                                            'type' => 'string',
                                                            'value' => '(',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 241,
                                                            'char' => 55,
                                                          ),
                                                          'right' => 
                                                          array (
                                                            'type' => 'variable',
                                                            'value' => 'regexp',
                                                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                            'line' => 241,
                                                            'char' => 64,
                                                          ),
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 241,
                                                          'char' => 64,
                                                        ),
                                                        'right' => 
                                                        array (
                                                          'type' => 'string',
                                                          'value' => ')',
                                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                          'line' => 241,
                                                          'char' => 67,
                                                        ),
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 241,
                                                        'char' => 67,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 241,
                                                      'char' => 67,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 242,
                                                  'char' => 37,
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
                                                      'operator' => 'concat-assign',
                                                      'variable' => 'route',
                                                      'expr' => 
                                                      array (
                                                        'type' => 'variable',
                                                        'value' => 'regexp',
                                                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                        'line' => 243,
                                                        'char' => 59,
                                                      ),
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 243,
                                                      'char' => 59,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 244,
                                                  'char' => 37,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 246,
                                              'char' => 39,
                                            ),
                                            3 => 
                                            array (
                                              'type' => 'let',
                                              'assignments' => 
                                              array (
                                                0 => 
                                                array (
                                                  'assign-type' => 'array-index',
                                                  'operator' => 'assign',
                                                  'variable' => 'matches',
                                                  'index-expr' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'variable',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 246,
                                                      'char' => 57,
                                                    ),
                                                  ),
                                                  'expr' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'tmp',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 246,
                                                    'char' => 64,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 246,
                                                  'char' => 64,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 247,
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
                                                  'assign-type' => 'variable',
                                                  'operator' => 'concat-assign',
                                                  'variable' => 'route',
                                                  'expr' => 
                                                  array (
                                                    'type' => 'string',
                                                    'value' => '([^/]*)',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 248,
                                                    'char' => 56,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 248,
                                                  'char' => 56,
                                                ),
                                                1 => 
                                                array (
                                                  'assign-type' => 'array-index',
                                                  'operator' => 'assign',
                                                  'variable' => 'matches',
                                                  'index-expr' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'item',
                                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                      'line' => 249,
                                                      'char' => 53,
                                                    ),
                                                  ),
                                                  'expr' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'tmp',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 249,
                                                    'char' => 60,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 249,
                                                  'char' => 60,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 250,
                                              'char' => 33,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 251,
                                          'char' => 29,
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
                                              'operator' => 'concat-assign',
                                              'variable' => 'route',
                                              'expr' => 
                                              array (
                                                'type' => 'concat',
                                                'left' => 
                                                array (
                                                  'type' => 'concat',
                                                  'left' => 
                                                  array (
                                                    'type' => 'string',
                                                    'value' => '{',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 252,
                                                    'char' => 47,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'item',
                                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                    'line' => 252,
                                                    'char' => 54,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 252,
                                                  'char' => 54,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '}',
                                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                  'line' => 252,
                                                  'char' => 57,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                                'line' => 252,
                                                'char' => 57,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                              'line' => 252,
                                              'char' => 57,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                          'line' => 253,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 255,
                                      'char' => 36,
                                    ),
                                    3 => 
                                    array (
                                      'type' => 'continue',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 256,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 257,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 258,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 259,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 259,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 261,
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
                      'type' => 'variable',
                      'value' => 'bracketCount',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 261,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 261,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 261,
                    'char' => 34,
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
                          'type' => 'variable',
                          'value' => 'ch',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 262,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'char',
                          'value' => '(',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 262,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 262,
                        'char' => 29,
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
                              'assign-type' => 'incr',
                              'variable' => 'parenthesesCount',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 263,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 264,
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
                              'type' => 'variable',
                              'value' => 'ch',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 264,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'char',
                              'value' => ')',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 264,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 264,
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
                                  'assign-type' => 'decr',
                                  'variable' => 'parenthesesCount',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 265,
                                  'char' => 43,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 267,
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
                                  'type' => 'variable',
                                  'value' => 'parenthesesCount',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 267,
                                  'char' => 42,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 267,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 267,
                                'char' => 46,
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
                                      'assign-type' => 'incr',
                                      'variable' => 'numberMatches',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 268,
                                      'char' => 44,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 269,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 270,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 271,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 271,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 273,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'bracketCount',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 273,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 273,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 273,
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
                          'assign-type' => 'incr',
                          'variable' => 'intermediate',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 274,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 275,
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
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parenthesesCount',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 276,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 276,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 276,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prevCh',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 276,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'char',
                            'value' => '\\\\',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 276,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 276,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 276,
                        'char' => 59,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'or',
                              'left' => 
                              array (
                                'type' => 'or',
                                'left' => 
                                array (
                                  'type' => 'equals',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ch',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 277,
                                    'char' => 28,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'char',
                                    'value' => '.',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 277,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 277,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'equals',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ch',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 277,
                                    'char' => 40,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'char',
                                    'value' => '+',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 277,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 277,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 277,
                                'char' => 46,
                              ),
                              'right' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ch',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 277,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'char',
                                  'value' => '|',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 277,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 277,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 277,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'ch',
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 277,
                                'char' => 64,
                              ),
                              'right' => 
                              array (
                                'type' => 'char',
                                'value' => '#',
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 277,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 277,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 277,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'route',
                                  'expr' => 
                                  array (
                                    'type' => 'char',
                                    'value' => '\\\\',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 278,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 278,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 279,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 280,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 282,
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
                          'operator' => 'concat-assign',
                          'variable' => 'route',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ch',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 282,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 282,
                          'char' => 31,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'prevCh',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ch',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 283,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 283,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 284,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 285,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 287,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 287,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 287,
                    'char' => 22,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'matches',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 287,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 287,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 287,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 288,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Extracts parameters from a string
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 155,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 155,
          'last-line' => 292,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBeforeMatch',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 295,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 295,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 295,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 296,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the \'before match\' callback if any
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'callable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 294,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 294,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 293,
          'last-line' => 300,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCompiledPattern',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 303,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'compiledPattern',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 303,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 303,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 304,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the route\'s compiled pattern
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 302,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 302,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 301,
          'last-line' => 308,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConverters',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 311,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'converters',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 311,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 311,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 312,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the router converter
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 310,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 310,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 309,
          'last-line' => 316,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getGroup',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 319,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'group',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 319,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 319,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 320,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the group associated with the route
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
                  'value' => 'GroupInterface',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 317,
                  'char' => 52,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 317,
                'char' => 52,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 318,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 318,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 317,
          'last-line' => 324,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpMethods',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 327,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'methods',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 327,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 327,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 328,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the HTTP methods that constraint matching the route
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 325,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 326,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 326,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 325,
          'last-line' => 332,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHostname',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 335,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'hostname',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 335,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 335,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 336,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the hostname restriction if any
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 334,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 334,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 333,
          'last-line' => 340,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMatch',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 343,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'match',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 343,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 343,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 344,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the \'match\' callback if any
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'callable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 342,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 342,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 341,
          'last-line' => 348,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 351,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 351,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 351,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 352,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the route\'s name
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 350,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 350,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 349,
          'last-line' => 356,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPaths',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 359,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'paths',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 359,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 359,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 360,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the paths
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 358,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 358,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 357,
          'last-line' => 364,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPattern',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 367,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'pattern',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 367,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 367,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 368,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the route\'s pattern
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 366,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 366,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 365,
          'last-line' => 372,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReversedPaths',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_flip',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 376,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 377,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 377,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 377,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 377,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 378,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the paths using positions as keys and names as values
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 374,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 374,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 373,
          'last-line' => 382,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRouteId',
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 385,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'id',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 385,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 385,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 386,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the route\'s id
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 384,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 384,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 383,
          'last-line' => 390,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getRoutePaths',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'paths',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 391,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 391,
              'char' => 58,
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 393,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'controllerName',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 393,
                  'char' => 39,
                ),
                2 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 393,
                  'char' => 51,
                ),
                3 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 393,
                  'char' => 58,
                ),
                4 => 
                array (
                  'variable' => 'routePaths',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 393,
                  'char' => 70,
                ),
                5 => 
                array (
                  'variable' => 'realClassName',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 394,
                  'char' => 26,
                ),
                6 => 
                array (
                  'variable' => 'namespaceName',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 394,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 396,
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
                  'type' => 'variable',
                  'value' => 'paths',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 396,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 396,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 396,
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
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 397,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 397,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 398,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 400,
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
                    'value' => 'paths',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 400,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 400,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 400,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 400,
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
                      'variable' => 'moduleName',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 401,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 401,
                      'char' => 34,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'controllerName',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 402,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 402,
                      'char' => 38,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'actionName',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 403,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 403,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 406,
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
                      'variable' => 'parts',
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
                              'value' => '::',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 406,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 406,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'paths',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 406,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 406,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 406,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 406,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 409,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'switch',
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
                          'value' => 'parts',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 409,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 409,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 409,
                    'char' => 33,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '3',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 411,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'moduleName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 412,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 412,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 412,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 412,
                              'char' => 46,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'controllerName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 413,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 413,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 413,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 413,
                              'char' => 50,
                            ),
                            2 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'actionName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 414,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '2',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 414,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 414,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 414,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 415,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 417,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 417,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 417,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'controllerName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 418,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 418,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 418,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 418,
                              'char' => 50,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'actionName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 419,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 419,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 419,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 419,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 420,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 422,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 422,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 422,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'controllerName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parts',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 423,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 423,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 423,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 423,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 424,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 425,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 425,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 427,
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
                      'variable' => 'routePaths',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 427,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 427,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 430,
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
                      'value' => 'moduleName',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 430,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 430,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 430,
                    'char' => 36,
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
                          'variable' => 'routePaths',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'module',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 431,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'moduleName',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 431,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 431,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 432,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 435,
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
                      'value' => 'controllerName',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 435,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 435,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 435,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
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
                              'value' => 'controllerName',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 437,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 437,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '\\\\',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 437,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 437,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 437,
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
                              'variable' => 'realClassName',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'get_class_ns',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'controllerName',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 439,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 439,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 439,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 439,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 442,
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
                              'variable' => 'namespaceName',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'get_ns_class',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'controllerName',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 442,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 442,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 442,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 442,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 445,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'namespaceName',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 445,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'routePaths',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'namespace',
                                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                      'line' => 446,
                                      'char' => 49,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'namespaceName',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 446,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 446,
                                  'char' => 66,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 447,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 448,
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
                              'variable' => 'realClassName',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'controllerName',
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 449,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 449,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 450,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 453,
                      'char' => 19,
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
                          'variable' => 'routePaths',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'controller',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 453,
                              'char' => 42,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'uncamelize',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'realClassName',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 453,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 453,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 453,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 453,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 454,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 457,
                  'char' => 14,
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
                      'value' => 'actionName',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 457,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 457,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 457,
                    'char' => 36,
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
                          'variable' => 'routePaths',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'action',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 458,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'actionName',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 458,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 458,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 459,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 460,
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
                      'variable' => 'routePaths',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 461,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 461,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 462,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 464,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePaths',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 464,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 464,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 464,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 464,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 464,
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
                          'value' => 'The route contains invalid paths',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 465,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 465,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 465,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 466,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 468,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'routePaths',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 468,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 469,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns routePaths
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 392,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 392,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 391,
          'last-line' => 484,
          'char' => 26,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'match',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 485,
              'char' => 39,
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
                  'property' => 'match',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'callback',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 487,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 487,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 489,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 489,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 490,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Allows to set a callback to handle the request directly in the route
     *
     *```php
     * $router->add(
     *     "/help",
     *     []
     * )->match(
     *     function () {
     *         return $this->getResponse()->redirect("https://support.google.com/", true);
     *     }
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 486,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 486,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 486,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 485,
          'last-line' => 494,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reConfigure',
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
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 495,
              'char' => 48,
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 495,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 495,
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
                  'variable' => 'routePaths',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 497,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'pcrePattern',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 497,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'compiledPattern',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 497,
                  'char' => 53,
                ),
                3 => 
                array (
                  'variable' => 'extracted',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 497,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 499,
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
                  'variable' => 'routePaths',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'getRoutePaths',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 499,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 499,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 499,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 499,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 504,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'starts_with',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 504,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 504,
                      'char' => 32,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '#',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 504,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 504,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 504,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 504,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
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
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 505,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 505,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '{',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 505,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 505,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 505,
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
                          'variable' => 'extracted',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 509,
                              'char' => 38,
                            ),
                            'name' => 'extractNamedParams',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pattern',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 509,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 509,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 509,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 509,
                          'char' => 66,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'pcrePattern',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'extracted',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 510,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 510,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 510,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 510,
                          'char' => 47,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'routePaths',
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
                                  'value' => 'routePaths',
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 511,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 511,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'extracted',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 511,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                    'line' => 511,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                  'line' => 511,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                                'line' => 511,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 511,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 511,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 512,
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
                          'variable' => 'pcrePattern',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pattern',
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 513,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 513,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 514,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 519,
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
                      'variable' => 'compiledPattern',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Router/Route.zep',
                          'line' => 519,
                          'char' => 40,
                        ),
                        'name' => 'compilePattern',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'pcrePattern',
                              'file' => '/app/phalcon/Mvc/Router/Route.zep',
                              'line' => 519,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Route.zep',
                            'line' => 519,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 519,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 519,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 520,
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
                      'variable' => 'compiledPattern',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Mvc/Router/Route.zep',
                        'line' => 521,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 521,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 522,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 527,
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
                  'property' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'pattern',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 527,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 527,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 532,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'compiledPattern',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'compiledPattern',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 532,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 532,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 537,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'paths',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'routePaths',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 537,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 537,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 538,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reconfigure the route adding a new pattern and a set of paths
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 496,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 495,
          'last-line' => 542,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'reset',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'uniqueId',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 545,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 545,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 546,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets the internal route id generator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 544,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 543,
          'last-line' => 550,
          'char' => 26,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setGroup',
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
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 551,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 551,
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
                  'property' => 'group',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'group',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 553,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 553,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 555,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 555,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 556,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the group associated with the route
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 552,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 552,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 552,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 551,
          'last-line' => 571,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHttpMethods',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'httpMethods',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 572,
              'char' => 51,
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 574,
                  'char' => 21,
                ),
                'name' => 'via',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpMethods',
                      'file' => '/app/phalcon/Mvc/Router/Route.zep',
                      'line' => 574,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 574,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 574,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 575,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
     *
     *```php
     * $route->setHttpMethods("GET");
     *
     * $route->setHttpMethods(
     *     [
     *         "GET",
     *         "POST",
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 573,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 573,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 573,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 572,
          'last-line' => 583,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHostname',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'hostname',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 584,
              'char' => 49,
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
                  'property' => 'hostname',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hostname',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 586,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 586,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 588,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 588,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 589,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a hostname restriction to the route
     *
     *```php
     * $route->setHostname("localhost");
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 585,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 585,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 585,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 584,
          'last-line' => 602,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 603,
              'char' => 40,
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
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 605,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 605,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 607,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 607,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 608,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the route\'s name
     *
     *```php
     * $router->add(
     *     "/about",
     *     [
     *         "controller" => "about",
     *     ]
     * )->setName("about");
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
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 604,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 604,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 604,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 603,
          'last-line' => 623,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'via',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'httpMethods',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 624,
              'char' => 40,
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
                  'property' => 'methods',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'httpMethods',
                    'file' => '/app/phalcon/Mvc/Router/Route.zep',
                    'line' => 626,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 626,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 628,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 628,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Route.zep',
              'line' => 629,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set one or more HTTP methods that constraint the matching of the route
     *
     *```php
     * $route->via("GET");
     *
     * $route->via(
     *     [
     *         "GET",
     *         "POST",
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
                  'value' => 'RouteInterface',
                  'file' => '/app/phalcon/Mvc/Router/Route.zep',
                  'line' => 625,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Route.zep',
                'line' => 625,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Route.zep',
            'line' => 625,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Route.zep',
          'line' => 624,
          'last-line' => 630,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router/Route.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Router/Route.zep',
    'line' => 20,
    'char' => 5,
  ),
);