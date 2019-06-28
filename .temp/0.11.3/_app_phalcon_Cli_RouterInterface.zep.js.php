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
    'file' => '/app/phalcon/Cli/RouterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
        'name' => 'Phalcon\\Cli\\Router\\RouteInterface',
        'file' => '/app/phalcon/Cli/RouterInterface.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Cli/RouterInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Cli\\Router
 *',
    'file' => '/app/phalcon/Cli/RouterInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  4 => 
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 23,
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 23,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 23,
              'char' => 58,
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
                  'file' => '/app/phalcon/Cli/RouterInterface.zep',
                  'line' => 23,
                  'char' => 79,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 23,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 23,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 28,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 28,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                  'file' => '/app/phalcon/Cli/RouterInterface.zep',
                  'line' => 33,
                  'char' => 58,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 33,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 33,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 38,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 38,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 43,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 43,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 48,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 48,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 53,
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
                  'file' => '/app/phalcon/Cli/RouterInterface.zep',
                  'line' => 53,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 53,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 53,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 58,
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
                  'file' => '/app/phalcon/Cli/RouterInterface.zep',
                  'line' => 58,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 58,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 58,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
                  'file' => '/app/phalcon/Cli/RouterInterface.zep',
                  'line' => 63,
                  'char' => 54,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 63,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 63,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
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
          'name' => 'getTaskName',
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 68,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 68,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 68,
          'last-line' => 74,
          'char' => 19,
        ),
        10 => 
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 75,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 75,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Handles routing information received from the rewrite engine
     *
     * @param array arguments
     *',
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 75,
          'last-line' => 79,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 80,
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
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 80,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 80,
          'last-line' => 84,
          'char' => 19,
        ),
        12 => 
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 85,
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
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 85,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 85,
          'last-line' => 89,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 90,
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
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 90,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 90,
          'last-line' => 94,
          'char' => 19,
        ),
        14 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cli/RouterInterface.zep',
              'line' => 95,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the default task name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 95,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 95,
          'last-line' => 99,
          'char' => 19,
        ),
        15 => 
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
                'file' => '/app/phalcon/Cli/RouterInterface.zep',
                'line' => 100,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/RouterInterface.zep',
            'line' => 100,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Cli/RouterInterface.zep',
          'line' => 100,
          'last-line' => 101,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cli/RouterInterface.zep',
      'line' => 101,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Cli/RouterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);