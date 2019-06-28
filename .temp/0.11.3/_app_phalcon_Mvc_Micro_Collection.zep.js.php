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
    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Micro',
    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
    'line' => 31,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Micro\\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *```php
 * $app = new \\Phalcon\\Mvc\\Micro();
 *
 * $collection = new Collection();
 *
 * $collection->setHandler(
 *     new PostsController()
 * );
 *
 * $collection->get("/posts/edit/{id}", "edit");
 *
 * $app->mount($collection);
 *```
 *',
    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
    'line' => 32,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Collection',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CollectionInterface',
        'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
        'line' => 33,
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
          'name' => 'handler',
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 36,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'handlers',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 36,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 38,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'lazy',
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 40,
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
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 46,
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 47,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 47,
              'char' => 61,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 47,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 47,
              'char' => 81,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 49,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'DELETE',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 49,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 49,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 49,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 49,
                    'char' => 42,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 49,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 49,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 49,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 49,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 49,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 51,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 51,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is DELETE.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 48,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 48,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 48,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 47,
          'last-line' => 58,
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 59,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 59,
              'char' => 58,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 59,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 59,
              'char' => 78,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 61,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'GET',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 61,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 61,
                    'char' => 25,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 61,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 61,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 61,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 61,
                    'char' => 48,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 61,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 61,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 61,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 63,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 63,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is GET.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 60,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 60,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 60,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 59,
          'last-line' => 68,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 71,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handler',
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 71,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 71,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 72,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 69,
          'last-line' => 76,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 79,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handlers',
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 79,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 79,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 77,
          'last-line' => 84,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 87,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'prefix',
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 87,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 87,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 88,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 86,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 85,
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 95,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 95,
              'char' => 59,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 95,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 95,
              'char' => 79,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 97,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HEAD',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 97,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 97,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 97,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 97,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 97,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 97,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 97,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 97,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 97,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 99,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 99,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 100,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is HEAD.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 96,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 96,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 95,
          'last-line' => 104,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 107,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'lazy',
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 107,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 107,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 106,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 106,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 105,
          'last-line' => 114,
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 115,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 115,
              'char' => 58,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 115,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 115,
              'char' => 78,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 117,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 117,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 117,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 117,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 117,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 117,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 117,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 117,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 117,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 117,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 119,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 119,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 116,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 116,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 116,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 115,
          'last-line' => 136,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'mapVia',
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 137,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 137,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 137,
              'char' => 73,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 137,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 137,
              'char' => 93,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 139,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 139,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 139,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 139,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 139,
                    'char' => 42,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 139,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 139,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 139,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 139,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 139,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 141,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 141,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 142,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler via methods.
     *
     * ```php
     * $collection->mapVia(
     *     "/test",
     *     "indexAction",
     *     ["POST", "GET"],
     *     "test"
     * );
     * ```
     *
     * @param callable handler
     * @param string|array method
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 138,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 137,
          'last-line' => 149,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 150,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 150,
              'char' => 62,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 150,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 150,
              'char' => 82,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 152,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'OPTIONS',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 152,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 152,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 152,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 152,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 152,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 152,
                    'char' => 52,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 152,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 152,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 152,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 154,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 154,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 155,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is
     * OPTIONS.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 151,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 151,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 150,
          'last-line' => 161,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 162,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 162,
              'char' => 60,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 162,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 162,
              'char' => 80,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 164,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PATCH',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 164,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 164,
                    'char' => 27,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 164,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 164,
                    'char' => 41,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 164,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 164,
                    'char' => 50,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 164,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 164,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 164,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 166,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 166,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is PATCH.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 163,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 162,
          'last-line' => 173,
          'char' => 19,
        ),
        11 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 174,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 174,
              'char' => 59,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 174,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 174,
              'char' => 79,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 176,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'POST',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 176,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 176,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 176,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 176,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 176,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 176,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 176,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 176,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 176,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 178,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 178,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 179,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is POST.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 175,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 174,
          'last-line' => 185,
          'char' => 19,
        ),
        12 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 186,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 186,
              'char' => 58,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 186,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 186,
              'char' => 78,
            ),
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 188,
                  'char' => 14,
                ),
                'name' => 'addMap',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'PUT',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 188,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 188,
                    'char' => 25,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePattern',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 188,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 188,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 188,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 188,
                    'char' => 48,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                      'line' => 188,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 188,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 188,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 190,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 190,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 191,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Maps a route to a handler that only matches if the HTTP method is PUT.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 187,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 187,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 187,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 186,
          'last-line' => 197,
          'char' => 19,
        ),
        13 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 198,
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
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 198,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 198,
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
                  'property' => 'handler',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handler',
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 200,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 200,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'lazy',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'lazy',
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 201,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 201,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 203,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 203,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 204,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the main handler.
     *
     * @param callable|string handler
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 199,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 198,
          'last-line' => 208,
          'char' => 19,
        ),
        14 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 209,
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
                  'property' => 'lazy',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'lazy',
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 211,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 211,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 213,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 213,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 214,
              'char' => 5,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 210,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 210,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 210,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 209,
          'last-line' => 218,
          'char' => 19,
        ),
        15 => 
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
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 219,
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
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 221,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 221,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 223,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 223,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 224,
              'char' => 5,
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
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 220,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                'line' => 220,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
            'line' => 220,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 219,
          'last-line' => 231,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'addMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 232,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'routePattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 232,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 232,
              'char' => 76,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 232,
              'char' => 89,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handlers',
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
                          'value' => 'method',
                          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                          'line' => 234,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                        'line' => 234,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'routePattern',
                          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                          'line' => 234,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                        'line' => 234,
                        'char' => 53,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                          'line' => 234,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                        'line' => 234,
                        'char' => 62,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                          'line' => 234,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                        'line' => 234,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                    'line' => 234,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
                  'line' => 234,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
              'line' => 235,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internal function to add a handler to the group.
     *
     * @param string|array    method
     * @param callable|string handler
     *',
          'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
          'line' => 232,
          'last-line' => 236,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
      'line' => 32,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Micro/Collection.zep',
    'line' => 32,
    'char' => 5,
  ),
);