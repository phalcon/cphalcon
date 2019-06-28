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
    'file' => '/app/phalcon/Mvc/Router/Group.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Router',
    'file' => '/app/phalcon/Mvc/Router/Group.zep',
    'line' => 60,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router\\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *```php
 * $router = new \\Phalcon\\Mvc\\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * //All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * //Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * //Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * //This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * //Add the group to the router
 * $router->mount($blog);
 *```
 *',
    'file' => '/app/phalcon/Mvc/Router/Group.zep',
    'line' => 61,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Group',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'GroupInterface',
        'file' => '/app/phalcon/Mvc/Router/Group.zep',
        'line' => 62,
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
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 64,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'hostname',
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 65,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'paths',
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 66,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'prefix',
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 67,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'routes',
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 71,
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
              'name' => 'paths',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 72,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 72,
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
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 74,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 74,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 74,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 74,
                  'char' => 35,
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
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 74,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 74,
                    'char' => 51,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 74,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 74,
                  'char' => 60,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 74,
                'char' => 60,
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
                      'property' => 'paths',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 75,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 75,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 78,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 78,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 78,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'initialize',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 78,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 78,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 78,
                'char' => 44,
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
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 79,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 79,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 79,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 79,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Router\\Group constructor
     *',
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 72,
          'last-line' => 89,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 90,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 90,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 90,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 90,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 90,
              'char' => 82,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 92,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 92,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 92,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 92,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 92,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpMethods',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 92,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 92,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 92,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router on any HTTP method
     *
     *```php
     * $router->add("/about", "About::index");
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 91,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 91,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 90,
          'last-line' => 99,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 100,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 100,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 100,
              'char' => 65,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 102,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 102,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 102,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 102,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 102,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'CONNECT',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 102,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 102,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 102,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is CONNECT
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 101,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 101,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 100,
          'last-line' => 109,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 110,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 110,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 110,
              'char' => 64,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 112,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 112,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 112,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 112,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 112,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'DELETE',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 112,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 112,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 112,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 113,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is DELETE
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 111,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 110,
          'last-line' => 119,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 120,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 120,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 120,
              'char' => 61,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 122,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 122,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 122,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 122,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 122,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'GET',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 122,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 122,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 122,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 123,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is GET
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 121,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 121,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 121,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 120,
          'last-line' => 129,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 130,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 130,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 130,
              'char' => 62,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 132,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 132,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 132,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 132,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 132,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HEAD',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 132,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 132,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 132,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 133,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is HEAD
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 131,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 131,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 131,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 130,
          'last-line' => 139,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 140,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 140,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 140,
              'char' => 65,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 142,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 142,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 142,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 142,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'OPTIONS',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 142,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 142,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 142,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Add a route to the router that only match if the HTTP method is OPTIONS
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 141,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 140,
          'last-line' => 149,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 150,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 150,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 150,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 152,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 152,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 152,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 152,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 152,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PATCH',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 152,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 152,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 152,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PATCH
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 151,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 151,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 150,
          'last-line' => 159,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 160,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 160,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 160,
              'char' => 62,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 162,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 162,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 162,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 162,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 162,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'POST',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 162,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 162,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 162,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 163,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is POST
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 161,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 161,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 161,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 160,
          'last-line' => 169,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 170,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 170,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 170,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 172,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 172,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 172,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 172,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 172,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PURGE',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 172,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 172,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 172,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 173,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PURGE
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 171,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 171,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 171,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 170,
          'last-line' => 179,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 180,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 180,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 180,
              'char' => 61,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 182,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 182,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 182,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 182,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 182,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PUT',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 182,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 182,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 182,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 183,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PUT
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 181,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 181,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 181,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 180,
          'last-line' => 189,
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 190,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 190,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 192,
                  'char' => 21,
                ),
                'name' => 'addRoute',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 192,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 192,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 192,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 192,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'TRACE',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 192,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 192,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 192,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 193,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is TRACE
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 191,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 191,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 191,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 190,
          'last-line' => 199,
          'char' => 19,
        ),
        12 => 
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
              'name' => 'beforeMatch',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 200,
              'char' => 54,
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
                    'value' => 'beforeMatch',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 202,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 202,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 204,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 204,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 205,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 201,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 201,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 201,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 200,
          'last-line' => 209,
          'char' => 20,
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
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 212,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 212,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 213,
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
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 211,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 210,
          'last-line' => 217,
          'char' => 19,
        ),
        14 => 
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 220,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 220,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 220,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 221,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 219,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 218,
          'last-line' => 225,
          'char' => 19,
        ),
        15 => 
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 228,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'hostname',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 228,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 228,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 229,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the hostname restriction
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 227,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 227,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 226,
          'last-line' => 233,
          'char' => 19,
        ),
        16 => 
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 236,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'paths',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 236,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 236,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 237,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the common paths defined for this group
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 234,
                'char' => 41,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 235,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 235,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 234,
          'last-line' => 241,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrefix',
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 244,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'prefix',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 244,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 244,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 245,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the common prefix for all the routes
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 243,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 243,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 242,
          'last-line' => 249,
          'char' => 19,
        ),
        18 => 
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 252,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'routes',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 252,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 252,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 253,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the routes added to the group
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 251,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 251,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 251,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 250,
          'last-line' => 257,
          'char' => 19,
        ),
        19 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 258,
              'char' => 48,
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
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 260,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 260,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 262,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 262,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 263,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a hostname restriction for all the routes in the group
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 259,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 259,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 259,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 258,
          'last-line' => 267,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPaths',
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 268,
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
                  'property' => 'paths',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paths',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 270,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 270,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 272,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 272,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 273,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set common paths for all the routes in the group
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 269,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 269,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 269,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 268,
          'last-line' => 277,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPrefix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 278,
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
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 280,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 280,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 282,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 282,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 283,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a common uri prefix for all the routes in this group
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 279,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 279,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 279,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 278,
          'last-line' => 287,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'addRoute',
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
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 288,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 288,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 288,
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
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 288,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 288,
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
                  'variable' => 'mergedPaths',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 290,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 290,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'defaultPaths',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 290,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'processedPaths',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 290,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 295,
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
                  'variable' => 'defaultPaths',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 295,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paths',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 295,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 295,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 295,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 297,
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
                    'value' => 'defaultPaths',
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 297,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 297,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 297,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 297,
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
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 298,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 298,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 298,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 298,
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
                          'variable' => 'processedPaths',
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
                                  'value' => 'paths',
                                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                  'line' => 299,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                'line' => 299,
                                'char' => 64,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 299,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 299,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 300,
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
                          'variable' => 'processedPaths',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'paths',
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 301,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 301,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 302,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 304,
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
                        'value' => 'processedPaths',
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 304,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 304,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 304,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 304,
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
                          'variable' => 'mergedPaths',
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
                                  'value' => 'defaultPaths',
                                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                  'line' => 308,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                'line' => 308,
                                'char' => 59,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'processedPaths',
                                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                  'line' => 308,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                                'line' => 308,
                                'char' => 75,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 308,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 308,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 309,
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
                          'variable' => 'mergedPaths',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultPaths',
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 310,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 310,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 311,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 312,
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
                      'variable' => 'mergedPaths',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 313,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 313,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 314,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 319,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Router/Group.zep',
                              'line' => 319,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'prefix',
                              'file' => '/app/phalcon/Mvc/Router/Group.zep',
                              'line' => 319,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 319,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pattern',
                            'file' => '/app/phalcon/Mvc/Router/Group.zep',
                            'line' => 319,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 319,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 319,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mergedPaths',
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 319,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 319,
                        'char' => 66,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'httpMethods',
                          'file' => '/app/phalcon/Mvc/Router/Group.zep',
                          'line' => 319,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Group.zep',
                        'line' => 319,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 319,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 319,
                  'char' => 80,
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
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 320,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 320,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 322,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'route',
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 322,
                  'char' => 15,
                ),
                'name' => 'setGroup',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Group.zep',
                      'line' => 322,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Group.zep',
                    'line' => 322,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 322,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 324,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'route',
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 324,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Router/Group.zep',
              'line' => 325,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a route applying the common attributes
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
                  'file' => '/app/phalcon/Mvc/Router/Group.zep',
                  'line' => 289,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Group.zep',
                'line' => 289,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Group.zep',
            'line' => 289,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Group.zep',
          'line' => 288,
          'last-line' => 326,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router/Group.zep',
      'line' => 61,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Router/Group.zep',
    'line' => 61,
    'char' => 5,
  ),
);