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
    'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Router',
    'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router\\RouteInterface
 *
 * Interface for Phalcon\\Mvc\\Router\\Route
 *',
    'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'RouteInterface',
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 23,
              'char' => 51,
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 23,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 23,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 28,
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 28,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Adds a converter to perform an additional transformation for certain parameter.
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
                  'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                  'line' => 28,
                  'char' => 77,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 28,
                'char' => 77,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 28,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCompiledPattern',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 33,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 33,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHostname',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 38,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 38,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpMethods',
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 43,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 43,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 43,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 48,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 48,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPaths',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 53,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 53,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPattern',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 58,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 58,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReversedPaths',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 63,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 63,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 63,
          'last-line' => 67,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRouteId',
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 68,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 68,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 73,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Sets a hostname restriction to the route
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
                  'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                  'line' => 73,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 73,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 73,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 73,
          'last-line' => 77,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 78,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets a set of HTTP methods that constraint the matching of the route
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
                  'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                  'line' => 78,
                  'char' => 72,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 78,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 78,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 78,
          'last-line' => 82,
          'char' => 19,
        ),
        12 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 83,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Sets the route\'s name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 83,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 83,
          'last-line' => 87,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 88,
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
                'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
                'line' => 88,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 88,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Reconfigure the route adding a new pattern and a set of paths
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 88,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'reset',
          'docblock' => '**
     * Resets the internal route id generator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 93,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 93,
          'last-line' => 97,
          'char' => 26,
        ),
        15 => 
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
              'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
              'line' => 98,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Set one or more HTTP methods that constraint the matching of the route
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
            'line' => 98,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
          'line' => 98,
          'last-line' => 99,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
      'line' => 99,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Router/RouteInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);