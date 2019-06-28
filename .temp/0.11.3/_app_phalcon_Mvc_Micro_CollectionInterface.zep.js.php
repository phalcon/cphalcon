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
    'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Micro',
    'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Micro\\CollectionInterface
 *
 * Interface for Phalcon\\Mvc\\Micro\\Collection
 *',
    'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'CollectionInterface',
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
          'name' => 'delete',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 23,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 23,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 23,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 23,
              'char' => 86,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is DELETE
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 23,
                  'char' => 112,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 23,
                'char' => 112,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 23,
            'char' => 112,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 28,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 28,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 28,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 28,
              'char' => 83,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is GET
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 28,
                  'char' => 109,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 28,
                'char' => 109,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 28,
            'char' => 109,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'getHandler',
          'docblock' => '**
     * Returns the main handler
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 33,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 33,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'getHandlers',
          'docblock' => '**
     * Returns the registered handlers
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
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 38,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 38,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'getPrefix',
          'docblock' => '**
     * Returns the collection prefix if any
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
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 43,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 43,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'head',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 48,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 48,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 48,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 48,
              'char' => 84,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is HEAD
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 48,
                  'char' => 110,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 48,
                'char' => 110,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 48,
            'char' => 110,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'isLazy',
          'docblock' => '**
     * Returns if the main handler must be lazy loaded
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
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 53,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 53,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'map',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 58,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 58,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 58,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 58,
              'char' => 83,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 58,
                  'char' => 109,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 58,
                'char' => 109,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 58,
            'char' => 109,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'options',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 63,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 63,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 63,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 63,
              'char' => 87,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is OPTIONS
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 63,
                  'char' => 113,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 63,
                'char' => 113,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 63,
            'char' => 113,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'patch',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 68,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 68,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 68,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 68,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is PATCH
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 68,
                  'char' => 111,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 68,
                'char' => 111,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 68,
            'char' => 111,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'post',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 73,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 73,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 73,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 73,
              'char' => 84,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is POST
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 73,
                  'char' => 110,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 73,
                'char' => 110,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 73,
            'char' => 110,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'put',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 78,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 78,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 78,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 78,
              'char' => 83,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is PUT
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 78,
                  'char' => 109,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 78,
                'char' => 109,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 78,
            'char' => 109,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'setHandler',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 83,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'lazy',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 83,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 83,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Sets the main handler
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 83,
                  'char' => 88,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 83,
                'char' => 88,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 83,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
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
          'name' => 'setLazy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'lazy',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 88,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Sets if the main handler must be lazy loaded
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 88,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 88,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 88,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        14 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
              'line' => 93,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets a prefix for all routes added to the collection
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
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                  'line' => 93,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
                'line' => 93,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
            'line' => 93,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
          'line' => 93,
          'last-line' => 94,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
      'line' => 94,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Micro/CollectionInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);