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
    'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\QueryInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Query
 *',
    'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'QueryInterface',
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
          'name' => 'cache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cacheOptions',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 25,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the cache parameters of the query
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 25,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 25,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 25,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 25,
          'last-line' => 31,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'execute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 32,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 32,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 32,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 32,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Executes a parsed PHQL statement
     *
     * @return mixed
     *',
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 32,
          'last-line' => 36,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindParams',
          'docblock' => '**
     * Returns default bind params
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 37,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 37,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 37,
          'last-line' => 41,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCacheOptions',
          'docblock' => '**
     * Returns the current cache options
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 42,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 42,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 42,
          'last-line' => 46,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindTypes',
          'docblock' => '**
     * Returns default bind types
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 47,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 47,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 47,
          'last-line' => 51,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSql',
          'docblock' => '**
     * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 52,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 52,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 52,
          'last-line' => 56,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSingleResult',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 57,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 57,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 57,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 57,
              'char' => 80,
            ),
          ),
          'docblock' => '**
     * Executes the query returning the first result
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
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 57,
                  'char' => 101,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 57,
                'char' => 101,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 57,
            'char' => 101,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 57,
          'last-line' => 61,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUniqueRow',
          'docblock' => '**
     * Check if the query is programmed to get only the first row in the resultset
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 62,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 62,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 62,
          'last-line' => 67,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'parse',
          'docblock' => '**
     * Parses the intermediate code produced by Phalcon\\Mvc\\Model\\Query\\Lang generating another
     * intermediate representation that could be executed by Phalcon\\Mvc\\Model\\Query
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
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 68,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 68,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBindParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 73,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 73,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 73,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Set default bind parameters
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 73,
                  'char' => 93,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 73,
                'char' => 93,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 73,
            'char' => 93,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 73,
          'last-line' => 77,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBindTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 78,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 78,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 78,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Set default bind parameters
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 78,
                  'char' => 91,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 78,
                'char' => 91,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 78,
            'char' => 91,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 78,
          'last-line' => 82,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSharedLock',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sharedLock',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 83,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 83,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Set SHARED LOCK clause
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 83,
                  'char' => 79,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 83,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 83,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 83,
          'last-line' => 87,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setUniqueRow',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uniqueRow',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
              'line' => 88,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Tells to the query if only the first row in the resultset must be returned
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
                  'value' => 'QueryInterface',
                  'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                  'line' => 88,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
                'line' => 88,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
            'line' => 88,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
          'line' => 88,
          'last-line' => 89,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
      'line' => 89,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/QueryInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);