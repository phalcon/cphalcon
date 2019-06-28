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
    'file' => '/app/phalcon/Db/ResultInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/ResultInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Db\\Result objects
 *',
    'file' => '/app/phalcon/Db/ResultInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ResultInterface',
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
          'name' => 'dataSeek',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'number',
              'const' => 0,
              'data-type' => 'long',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/ResultInterface.zep',
              'line' => 22,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Moves internal resultset cursor to another position letting us to fetch a
     * certain row
     *',
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 22,
          'last-line' => 28,
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
          'docblock' => '**
     * Allows to executes the statement again. Some database systems don\'t
     * support scrollable cursors. So, as cursors are forward only, we need to
     * execute the cursor again to fetch rows from the begining
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 29,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 29,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 29,
          'last-line' => 35,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetch',
          'docblock' => '**
     * Fetches an array/object of strings that corresponds to the fetched row,
     * or FALSE if there are no more rows. This method is affected by the active
     * fetch flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 36,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 36,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 36,
          'last-line' => 42,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchAll',
          'docblock' => '**
     * Returns an array of arrays containing all the records in the result. This
     * method is affected by the active fetch flag set using
     * `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 43,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 43,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 43,
          'last-line' => 49,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchArray',
          'docblock' => '**
     * Returns an array of strings that corresponds to the fetched row, or FALSE
     * if there are no more rows. This method is affected by the active fetch
     * flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 50,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 50,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInternalResult',
          'docblock' => '**
     * Gets the internal PDO result object
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
                  'value' => '\\PDOStatement',
                  'file' => '/app/phalcon/Db/ResultInterface.zep',
                  'line' => 55,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 55,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 55,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 55,
          'last-line' => 59,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'numRows',
          'docblock' => '**
     * Gets number of rows returned by a resultset
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 60,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 60,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 60,
          'last-line' => 64,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFetchMode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/ResultInterface.zep',
              'line' => 65,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Changes the fetching mode affecting Phalcon\\Db\\Result\\Pdo::fetch()
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
                'file' => '/app/phalcon/Db/ResultInterface.zep',
                'line' => 65,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/ResultInterface.zep',
            'line' => 65,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Db/ResultInterface.zep',
          'line' => 65,
          'last-line' => 66,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/ResultInterface.zep',
      'line' => 66,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Db/ResultInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);