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
    'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli\\Router',
    'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Cli\\Router\\Route
 *',
    'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
    'line' => 16,
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
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 22,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Replaces placeholders from pattern returning a valid PCRE regular
     * expression
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 22,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 22,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 22,
          'last-line' => 26,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'delimiter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 27,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 27,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Set the routing delimiter
     *',
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 27,
          'last-line' => 31,
          'char' => 26,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 32,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 32,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 32,
          'last-line' => 36,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getDelimiter',
          'docblock' => '**
     * Get routing delimiter
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 37,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 37,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 37,
          'last-line' => 41,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDescription',
          'docblock' => '**
     * Returns the route\'s description
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 42,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 42,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 42,
          'last-line' => 46,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 47,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 47,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 47,
          'last-line' => 51,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 52,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 52,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 52,
          'last-line' => 56,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 57,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 57,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 57,
          'last-line' => 61,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 62,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 62,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 62,
          'last-line' => 66,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 67,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 67,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 67,
          'last-line' => 71,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 72,
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
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 72,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 72,
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
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 72,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 72,
          'last-line' => 76,
          'char' => 19,
        ),
        11 => 
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
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 77,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 77,
          'last-line' => 81,
          'char' => 26,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDescription',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'description',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 82,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Sets the route\'s description
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
                  'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                  'line' => 82,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 82,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 82,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 82,
          'last-line' => 86,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
              'line' => 87,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Sets the route\'s name
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
                  'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                  'line' => 87,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
                'line' => 87,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
            'line' => 87,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
          'line' => 87,
          'last-line' => 88,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
      'line' => 88,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Cli/Router/RouteInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);