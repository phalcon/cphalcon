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
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Router',
        'file' => '/app/phalcon/Mvc/RouterInterface.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\RouteInterface',
        'file' => '/app/phalcon/Mvc/RouterInterface.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\GroupInterface',
        'file' => '/app/phalcon/Mvc/RouterInterface.zep',
        'line' => 15,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Mvc\\Router
 *',
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  6 => 
  array (
    'type' => 'interface',
    'name' => 'RouterInterface',
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 25,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 25,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 25,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 25,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 25,
              'char' => 82,
            ),
          ),
          'docblock' => '**
     * Adds a route to the router on any HTTP method
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 25,
                  'char' => 103,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 25,
                'char' => 103,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 25,
            'char' => 103,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 30,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 30,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 30,
                  'char' => 88,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'POSITION_LAST',
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 30,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 30,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 30,
              'char' => 88,
            ),
          ),
          'docblock' => '**
     * Attach Route object to the routes stack.
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 30,
                  'char' => 110,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 30,
                'char' => 110,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 30,
            'char' => 110,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 30,
          'last-line' => 34,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 35,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 35,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 35,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 35,
                  'char' => 86,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 35,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 35,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 35,
          'last-line' => 39,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 40,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 40,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 40,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 40,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 40,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 40,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 40,
          'last-line' => 44,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 45,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 45,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 45,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 45,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 45,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 45,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 50,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 50,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 50,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 50,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 50,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 50,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 50,
          'last-line' => 54,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 55,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 55,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 55,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 55,
                  'char' => 86,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 55,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 55,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 55,
          'last-line' => 59,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 60,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 60,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 60,
              'char' => 59,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 60,
                  'char' => 80,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 60,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 60,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 60,
          'last-line' => 64,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 65,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 65,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 65,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 65,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 65,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 65,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 65,
          'last-line' => 70,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 71,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 71,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 71,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 71,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 71,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 71,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 71,
          'last-line' => 75,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 76,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 76,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 76,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 76,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 76,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 76,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 76,
          'last-line' => 80,
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 81,
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 81,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 81,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 81,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 81,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 81,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 81,
          'last-line' => 85,
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
     * Removes all the defined routes
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 86,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActionName',
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 91,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 91,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerName',
          'docblock' => '**
     * Returns processed controller name
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 96,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 96,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMatchedRoute',
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 101,
                  'char' => 58,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 101,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 101,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 101,
          'last-line' => 105,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMatches',
          'docblock' => '**
     * Return the sub expressions in the regular expression matched
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 106,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 106,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 106,
          'last-line' => 110,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModuleName',
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 111,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 111,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 111,
          'last-line' => 115,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNamespaceName',
          'docblock' => '**
     * Returns processed namespace name
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 116,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 116,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 116,
          'last-line' => 120,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 121,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 121,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 121,
          'last-line' => 125,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRoutes',
          'docblock' => '**
     * Return all the routes defined in the router
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 126,
                  'char' => 54,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 126,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 126,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 126,
          'last-line' => 130,
          'char' => 19,
        ),
        21 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 131,
              'char' => 40,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 131,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 131,
                'char' => 62,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 131,
                'char' => 68,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 131,
            'char' => 68,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 131,
          'last-line' => 135,
          'char' => 19,
        ),
        22 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 136,
              'char' => 48,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 136,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 136,
                'char' => 70,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 136,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 136,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 136,
          'last-line' => 140,
          'char' => 19,
        ),
        23 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 141,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Handles routing information received from the rewrite engine
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 141,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 141,
          'last-line' => 145,
          'char' => 19,
        ),
        24 => 
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 146,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 146,
              'char' => 49,
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
                  'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                  'line' => 146,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 146,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 146,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 146,
          'last-line' => 150,
          'char' => 19,
        ),
        25 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 151,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Sets the default action name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 151,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 151,
          'last-line' => 155,
          'char' => 19,
        ),
        26 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 156,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Sets the default controller name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 156,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 156,
          'last-line' => 160,
          'char' => 19,
        ),
        27 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 161,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Sets the name of the default module
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 161,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 161,
          'last-line' => 165,
          'char' => 19,
        ),
        28 => 
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
              'file' => '/app/phalcon/Mvc/RouterInterface.zep',
              'line' => 166,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Sets an array of default paths
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 166,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 166,
          'last-line' => 170,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'wasMatched',
          'docblock' => '**
     * Check if the router matches any of the defined routes
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
                'file' => '/app/phalcon/Mvc/RouterInterface.zep',
                'line' => 171,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/RouterInterface.zep',
            'line' => 171,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/RouterInterface.zep',
          'line' => 171,
          'last-line' => 172,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/RouterInterface.zep',
      'line' => 172,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/RouterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);