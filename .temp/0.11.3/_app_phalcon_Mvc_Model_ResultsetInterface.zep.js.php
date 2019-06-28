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
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
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
        'name' => 'Closure',
        'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
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
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
        'line' => 16,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
    'line' => 22,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\ResultsetInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Resultset
 *',
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
    'line' => 23,
    'char' => 9,
  ),
  7 => 
  array (
    'type' => 'interface',
    'name' => 'ResultsetInterface',
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
              'name' => 'conditionCallback',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Closure',
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 28,
                'char' => 54,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 28,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 28,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Deletes every record in the resultset
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
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 28,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 28,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 28,
          'last-line' => 42,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'filter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 43,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Filters a resultset returning only those the developer requires
     *
     *```php
     * $filtered = $robots->filter(
     *     function ($robot) {
     *         if ($robot->id < 3) {
     *             return $robot;
     *         }
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
                  'value' => 'ModelInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 43,
                  'char' => 66,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 43,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 43,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCache',
          'docblock' => '**
     * Returns the associated cache for the resultset
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 48,
                  'char' => 53,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 48,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 48,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFirst',
          'docblock' => '**
     * Get first row in the resultset
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
                  'value' => 'ModelInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 53,
                  'char' => 52,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 53,
                'char' => 52,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 53,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 53,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHydrateMode',
          'docblock' => '**
     * Returns the current hydration mode
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 58,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 58,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLast',
          'docblock' => '**
     * Get last row in the resultset
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
                  'value' => 'ModelInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 63,
                  'char' => 51,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 63,
                'char' => 51,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 63,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 63,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 63,
          'last-line' => 67,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns the error messages produced by a batch operation
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 68,
                  'char' => 58,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 68,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 68,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Returns the internal type of data retrieval that the resultset is using
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 73,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 73,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 73,
          'last-line' => 77,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isFresh',
          'docblock' => '**
     * Tell if the resultset if fresh or an old one cached
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
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 78,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 78,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 78,
          'last-line' => 82,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHydrateMode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'hydrateMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 83,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets the hydration mode in the resultset
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
                  'value' => 'ResultsetInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 83,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 83,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 83,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 83,
          'last-line' => 87,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setIsFresh',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'isFresh',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 88,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Set if the resultset is fresh or an old one cached
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
                  'value' => 'ResultsetInterface',
                  'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                  'line' => 88,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 88,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 88,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 88,
          'last-line' => 93,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
          'docblock' => '**
     * Returns a complete resultset as an array, if the resultset has a big number of rows
     * it could consume more memory than currently it does.
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
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 94,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 94,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 94,
          'last-line' => 100,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'update',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 101,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditionCallback',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Closure',
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 101,
                'char' => 64,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 101,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
              'line' => 101,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Updates every record in the resultset
     *
     * @param array data
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
                'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
                'line' => 101,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
            'line' => 101,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
          'line' => 101,
          'last-line' => 102,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
      'line' => 102,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/ResultsetInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);