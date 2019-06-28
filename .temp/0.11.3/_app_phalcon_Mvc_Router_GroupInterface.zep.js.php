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
    'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Router',
    'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\RouteInterface',
        'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
    'line' => 60,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router\\GroupInterface
 *
 *```php
 * $router = new \\Phalcon\\Mvc\\Router();
 *
 * // Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * // All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * // Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * // Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * // This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * // Add the group to the router
 * $router->mount($blog);
 *```
 *',
    'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
    'line' => 61,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'GroupInterface',
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 70,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 70,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 70,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 70,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 70,
              'char' => 82,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router on any HTTP method
     *
     *```php
     * router->add("/about", "About::index");
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 70,
                  'char' => 103,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 70,
                'char' => 103,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 70,
            'char' => 103,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 70,
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 75,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 75,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 75,
              'char' => 65,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 75,
                  'char' => 86,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 75,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 75,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 75,
          'last-line' => 79,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 80,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 80,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 80,
              'char' => 64,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 80,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 80,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 80,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 80,
          'last-line' => 84,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 85,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 85,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 85,
              'char' => 61,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 85,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 85,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 85,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 85,
          'last-line' => 89,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 90,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 90,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 90,
              'char' => 62,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 90,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 90,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 90,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 90,
          'last-line' => 94,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 95,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 95,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 95,
              'char' => 65,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 95,
                  'char' => 86,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 95,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 95,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 95,
          'last-line' => 99,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 100,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 100,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 100,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 100,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 100,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 100,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 100,
          'last-line' => 104,
          'char' => 19,
        ),
        7 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 105,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 105,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 105,
              'char' => 62,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 105,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 105,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 105,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 105,
          'last-line' => 109,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 110,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 110,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 110,
              'char' => 63,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router that only match if the HTTP method is PURGE
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 110,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 110,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 110,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 110,
          'last-line' => 114,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 115,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 115,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 115,
              'char' => 61,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 115,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 115,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 115,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 115,
          'last-line' => 119,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 120,
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 120,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 120,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 120,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 120,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 120,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 120,
          'last-line' => 126,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 127,
              'char' => 53,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 127,
                  'char' => 74,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 127,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 127,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 127,
          'last-line' => 131,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
          'docblock' => '**
     * Removes all the pre-defined routes
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 132,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 132,
          'last-line' => 136,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBeforeMatch',
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 137,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 137,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 137,
          'last-line' => 141,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHostname',
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 142,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 142,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 142,
          'last-line' => 146,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPaths',
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 147,
                'char' => 41,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 147,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 147,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 147,
          'last-line' => 151,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrefix',
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
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 152,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 152,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 152,
          'last-line' => 156,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRoutes',
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 157,
                  'char' => 54,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 157,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 157,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 157,
          'last-line' => 161,
          'char' => 19,
        ),
        18 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 162,
              'char' => 48,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 162,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 162,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 162,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 162,
          'last-line' => 168,
          'char' => 19,
        ),
        19 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 169,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Set common paths for all the routes in the group
     *
     * @param array paths
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 169,
                  'char' => 60,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 169,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 169,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 169,
          'last-line' => 173,
          'char' => 19,
        ),
        20 => 
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
              'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
              'line' => 174,
              'char' => 44,
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
                  'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                  'line' => 174,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
                'line' => 174,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
            'line' => 174,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
          'line' => 174,
          'last-line' => 175,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
      'line' => 175,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Router/GroupInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);